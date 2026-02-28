# ============================================================
# LX32 Makefile :: SystemVerilog Simulation (Verilator 5.044)
# ============================================================

SHELL := /bin/sh
VERILATOR       ?= verilator
VERILATOR_FLAGS ?= -Wall -Wno-fatal --binary --trace --trace-structs -O2 --timing

OUTDIR          := .sim

# Relative paths
RTL_CORE        := rtl/core
RTL_ARCH        := rtl/arch
TB_CORE         := tb/core

.PHONY: help sim clean

help:
	@echo "Usage: make sim TB=lx32_system_tb"

sim:
	@if [ -z "$(TB)" ]; then echo "ERROR: Define TB=<name>"; exit 2; fi
	@mkdir -p "$(OUTDIR)/$(TB)"
	@echo "Compiling System: $(TB)..."
	
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TB) \
		--Mdir $(OUTDIR)/$(TB) \
		$(RTL_ARCH)/*.sv \
		$(RTL_CORE)/*.sv \
		$(TB_CORE)/$(TB).sv \
		-o $(TB)_sim
	
	@echo "Running simulation..."
	./$(OUTDIR)/$(TB)/$(TB)_sim +trace

lint:
	@echo "Running Lint check for all RTL..."
	$(VERILATOR) --lint-only -Wall -Wno-fatal \
		$(RTL_ARCH)/*.sv \
		$(RTL_CORE)/*.sv

clean:
	@rm -rf $(OUTDIR)
