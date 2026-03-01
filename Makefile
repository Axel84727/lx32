# ============================================================
# LX32 Makefile :: SystemVerilog Simulation (Verilator portable)
# ============================================================

SHELL := /bin/sh
VERILATOR ?= verilator
VERILATOR_FLAGS ?= -Wall -Wno-fatal --binary --trace --trace-structs -O2 --timing

OUTDIR := .sim
ROOT_DIR := $(CURDIR)
LIB_OUTDIR := $(abspath $(OUTDIR)/lx32_lib)

# Relative paths
RTL_CORE := rtl/core
RTL_ARCH := rtl/arch
TB_CORE  := tb/core

.PHONY: help sim clean

# Verilator include path detection (Linux vs macOS)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
  # macOS (Homebrew)
  VERILATOR_ROOT := $(shell brew --prefix verilator)/share/verilator
else
  # Linux (apt or general)
  VERILATOR_ROOT := /usr/share/verilator
endif
VERILATOR_INC := $(VERILATOR_ROOT)/include

VALIDATOR_DIR := tools/lx32_validator

librust:
	@rm -rf "$(LIB_OUTDIR)"
	@mkdir -p "$(LIB_OUTDIR)"
	@chmod -R u+rwX "$(OUTDIR)"
	@test -d "$(LIB_OUTDIR)"
	@test -w "$(LIB_OUTDIR)"
	# 1. Generate C++ files
	$(VERILATOR) -Wall --cc \
		--Mdir $(LIB_OUTDIR) \
		rtl/arch/*.sv \
		rtl/core/*.sv \
		--top-module lx32_system

	# 2. Compile the bridge (portable include handling)
	g++ -c -fPIC $(VALIDATOR_DIR)/src/bridge.cpp \
		-I$(LIB_OUTDIR) \
		-I$(VERILATOR_INC) \
		-I$(VERILATOR_INC)/vltstd \
		-o $(ROOT_DIR)/.sim/bridge.o

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
