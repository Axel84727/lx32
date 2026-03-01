use std::env;
use std::fs;
use std::path::PathBuf;

fn main() {
    // Detect the location of Verilator: prefer VERILATOR_ROOT if set,
    // otherwise guess by platform.
    let verilator_root = env::var("VERILATOR_ROOT").unwrap_or_else(|_| {
        if cfg!(target_os = "macos") {
            // Check for Homebrew (Apple Silicon and Intel), and MacPorts
            let candidates = [
                "/opt/homebrew/opt/verilator/share/verilator", // Homebrew Apple Silicon
                "/usr/local/opt/verilator/share/verilator",    // Homebrew Intel
                "/opt/local/share/verilator",                  // MacPorts (if used)
            ];
            candidates
                .iter()
                .map(PathBuf::from)
                .find(|p| p.exists())
                .map(|p| p.to_string_lossy().to_string())
                .unwrap_or_else(|| {
                    panic!(
                        "Could not find Verilator in common macOS locations. \
                        Install with 'brew install verilator' or set VERILATOR_ROOT"
                    )
                })
        } else {
            // Standard Linux path
            "/usr/share/verilator".to_string()
        }
    });
    let verilator_inc = format!("{}/include", verilator_root);

    // Path to the Verilator-generated files
    let gen_dir = "../../.sim/lx32_lib";

    let mut builder = cc::Build::new();
    builder
        .cpp(true)
        .warnings(false) // Silence dozens of Verilator header warnings
        .file("src/bridge.cpp")
        .file(format!("{}/verilated.cpp", verilator_inc))
        .include(gen_dir)
        .file(format!("{}/verilated_threads.cpp", verilator_inc))
        .include(&verilator_inc)
        .include(format!("{}/vltstd", verilator_inc));

    // Automatically include every .cpp file Verilator generated in that folder
    if let Ok(entries) = fs::read_dir(gen_dir) {
        for entry in entries.flatten() {
            let path = entry.path();
            if let Some(ext) = path.extension() {
                if ext == "cpp" {
                    println!("cargo:rerun-if-changed={}", path.display());
                    builder.file(path);
                }
            }
        }
    } else {
        panic!(
            "RTL build directory {} not found. Run Verilator first!",
            gen_dir
        );
    }

    builder.compile("lx32_bridge");

    // Tell Cargo where to find the compiled static library (OUT_DIR)
    let out_dir = env::var("OUT_DIR").unwrap();
    println!("cargo:rustc-link-search=native={}", out_dir);

    // Tell Cargo to link the bridge static library
    println!("cargo:rustc-link-lib=static=lx32_bridge");

    // Link the C++ standard library
    if cfg!(target_os = "macos") {
        println!("cargo:rustc-link-lib=c++");
    } else {
        println!("cargo:rustc-link-lib=c++");
    }

    println!("cargo:rerun-if-changed=src/bridge.cpp");
}
