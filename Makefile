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


# Detect OS and set Verilator paths accordingly
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	VERILATOR_ROOT := /opt/homebrew/Cellar/verilator/5.044/share/verilator
else
	VERILATOR_ROOT := /usr/share/verilator
endif

VERILATOR_INC  := $(VERILATOR_ROOT)/include
VALIDATOR_DIR  := tools/lx32_validator

librust:
	@mkdir -p .sim/lx32_lib
	# 1. Generate C++ files
	verilator -Wall --cc \
		--Mdir .sim/lx32_lib \
		rtl/arch/*.sv \
		rtl/core/*.sv \
		--top-module lx32_system

	# 2. Compile the bridge using the correct Homebrew paths
	g++ -c -fPIC $(VALIDATOR_DIR)/src/bridge.cpp \
		-I.sim/lx32_lib \
		-I$(VERILATOR_INC) \
		-I$(VERILATOR_INC)/vltstd \
		-o .sim/bridge.o
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

clean:
	@rm -rf $(OUTDIR)
