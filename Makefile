SHELL := /bin/sh

IVL ?= iverilog
VVP ?= vvp
IVLFLAGS ?= -g2012

ROOT := $(CURDIR)
OUTDIR ?= $(ROOT)/.sim

RTL_CORE := $(ROOT)/rtl/core
TB_CORE := $(ROOT)/tb/core

PKGS := $(RTL_CORE)/lx32_pkg.sv $(RTL_CORE)/branches_pkg.sv
RTL_SRCS := $(PKGS) $(filter-out $(PKGS),$(wildcard $(RTL_CORE)/*.sv))
TB_SRCS := $(wildcard $(TB_CORE)/*_tb.sv)
TB_NAMES := $(notdir $(TB_SRCS))
TB_TARGETS := $(TB_NAMES:.sv=)

.PHONY: help sim sim-all list-tb clean

help:
	@echo "Targets:"
	@echo "  sim TB=<name>      Compile and run a single testbench (e.g. TB=alu_tb)"
	@echo "  sim-all            Compile and run all testbenches"
	@echo "  list-tb            List available testbenches"
	@echo "  clean              Remove build artifacts"
	@echo "Vars: IVL, VVP, IVLFLAGS, OUTDIR"

list-tb:
	@for tb in $(TB_TARGETS); do echo $$tb; done

sim:
	@if [ -z "$(TB)" ]; then \
		echo "ERROR: TB is required (e.g. make sim TB=alu_tb)"; \
		exit 2; \
	fi
	@if [ ! -f "$(TB_CORE)/$(TB).sv" ]; then \
		echo "ERROR: Testbench not found: $(TB_CORE)/$(TB).sv"; \
		exit 2; \
	fi
	@mkdir -p "$(OUTDIR)"
	$(IVL) $(IVLFLAGS) -s $(TB) -o "$(OUTDIR)/$(TB).vvp" $(RTL_SRCS) "$(TB_CORE)/$(TB).sv"
	$(VVP) "$(OUTDIR)/$(TB).vvp"

sim-all:
	@for tb in $(TB_TARGETS); do \
		$(MAKE) --no-print-directory sim TB=$$tb; \
	done

clean:
	@rm -rf "$(OUTDIR)"
