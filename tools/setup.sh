#!/bin/bash

# ==============================================================================
# LX32 Environment Setup & Verification Script
# Target: macOS & Linux (Unix-compatible)
# ==============================================================================

# Exit immediately if a command exits with a non-zero status
set -e

# ANSI Color Codes for a professional terminal output
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}==> [1/4] Checking System Dependencies...${NC}"

# Check required tools for simulation, formal verification, and closure runs
required_tools=(verilator cargo coqc sby yosys z3 g++)
for tool in "${required_tools[@]}"; do
    if ! command -v "$tool" &> /dev/null; then
        echo -e "${RED}Error: '$tool' not found. Install required dependencies before running setup.${NC}"
        exit 1
    fi
done

# Determine Project Root (works regardless of where the script is called from)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Navigate to project root to execute Make commands
cd "$PROJECT_ROOT"

echo -e "${BLUE}==> [2/4] Generating RTL-to-Rust Bridge...${NC}"
# Generates the C++ headers and shared objects via Verilator
make librust

echo -e "${BLUE}==> [3/4] Compiling Rust Validator (Release Mode)...${NC}"
# Compiling the validator. Warnings are managed via Cargo.toml [lints]
cargo build --release --manifest-path tools/lx32_validator/Cargo.toml

echo -e "${BLUE}==> [4/4] Running Initial Validation Suite...${NC}"
# Executes the default test suite to ensure everything is wired correctly
make validate

echo -e "${GREEN}✨ Success! The LX32 environment is fully compiled and verified.${NC}"
echo -e "To explore more testing options, run: ${BLUE}make validate-help${NC}"
