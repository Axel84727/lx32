use std::env;
use std::fs;
use std::path::PathBuf;

fn main() {
    // Universal Verilator include root detection
    // 1. Si VERILATOR_ROOT está en el entorno, úsalo
    // 2. Si no, inferir según sistema
    let verilator_root = env::var("VERILATOR_ROOT").unwrap_or_else(|_| {
        // Mac (Homebrew - Apple Silicon y x86)
        if cfg!(target_os = "macos") {
            // Soportar Homebrew y MacPorts si es necesario
            let brew_dir1 = "/opt/homebrew/opt/verilator/share/verilator"; // Apple Silicon default
            let brew_dir2 = "/usr/local/opt/verilator/share/verilator";    // Intel default
            let macports_dir = "/opt/local/share/verilator";               // MacPorts
            if PathBuf::from(brew_dir1).exists() {
                brew_dir1.to_string()
            } else if PathBuf::from(brew_dir2).exists() {
                brew_dir2.to_string()
            } else if PathBuf::from(macports_dir).exists() {
                macports_dir.to_string()
            } else {
                panic!(
                    "No se encontró Verilator, define VERILATOR_ROOT o instala con brew install verilator"
                );
            }
        } else {
            // Linux (Apt, etc)
            "/usr/share/verilator".to_string()
        }
    });
    let verilator_inc = format!("{}/include", verilator_root);

    // Path to the generated files
    let gen_dir = "../../.sim/lx32_lib";

    let mut builder = cc::Build::new();
    builder
        .cpp(true)
        .warnings(false) // Silence Verilator header warnings
        .file("src/bridge.cpp")
        .file(format!("{}/verilated.cpp", verilator_inc))
        .include(gen_dir)
        .file(format!("{}/verilated_threads.cpp", verilator_inc))
        .include(&verilator_inc)
        .include(format!("{}/vltstd", verilator_inc));

    // Recopila todos los .cpp generados por Verilator
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

    // 1. Cargo link (OUT_DIR)
    let out_dir = env::var("OUT_DIR").unwrap();
    println!("cargo:rustc-link-search=native={}", out_dir);

    // 2. Bridge static library
    println!("cargo:rustc-link-lib=static=lx32_bridge");

    // 3. Link correct C++ standard library
    if cfg!(target_os = "macos") {
        println!("cargo:rustc-link-lib=c++");
    } else {
        println!("cargo:rustc-link-lib=c++");
        // Si deseas máxima compatibilidad con distros viejas de Linux agrega también:
        // println!("cargo:rustc-link-lib=stdc++");
    }

    println!("cargo:rerun-if-changed=src/bridge.cpp");
}
