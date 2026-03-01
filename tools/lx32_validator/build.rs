use std::env;
use std::fs;


fn main() {
    let verilator_root = env::var("VERILATOR_ROOT")
        .unwrap_or_else(|_| "/opt/homebrew/opt/verilator/share/verilator".to_string());
    let verilator_inc = format!("{}/include", verilator_root);

    // Path to the generated files
    let gen_dir = "../../.sim/lx32_lib";

    let mut builder = cc::Build::new();
    builder
        .cpp(true)
        .warnings(false) // Silence the 58+ Verilator header warnings
        .file("src/bridge.cpp")
        .file(format!("{}/verilated.cpp", verilator_inc))
        .include(gen_dir)
        .file(format!("{}/verilated_threads.cpp", verilator_inc))
        .include(&verilator_inc)
        .include(format!("{}/vltstd", verilator_inc));

    // Automatically collect every .cpp file Verilator threw into that folder
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
            "RTL build directory {} not found. Run verilator first!",
            gen_dir
        );
    }

    builder.compile("lx32_bridge");

    // 1. Tell Cargo where to find the compiled static library (OUT_DIR)
    let out_dir = env::var("OUT_DIR").unwrap();
    println!("cargo:rustc-link-search=native={}", out_dir);

    // 2. Tell Cargo to link the bridge library
    println!("cargo:rustc-link-lib=static=lx32_bridge");

    // 3. Link the C++ standard library (libc++ on macOS)
    println!("cargo:rustc-link-lib=c++");

    println!("cargo:rerun-if-changed=src/bridge.cpp");

    println!("cargo:rustc-link-lib=c++");
    println!("cargo:rerun-if-changed=src/bridge.cpp");
}
