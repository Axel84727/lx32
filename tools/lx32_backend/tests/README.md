# LX32 Backend Smoke Tests

This folder contains minimal backend smoke tests for early bring-up.

## Scope

These tests validate the first usable SelectionDAG slice:

- formal argument lowering for fixed-arg integer functions,
- return lowering,
- DAG selector wiring in `LX32TargetMachine`.

It also contains a bare-metal C smoke slice for firmware-focused bring-up.

## Run

```bash
bash /Users/axel/lx32/tools/lx32_backend/tests/run_smoke.sh /path/to/llc
```

If no argument is provided, the script tries:

- `/Users/axel/llvm-project/build/bin/llc`
- `llc` from `PATH`

## Notes

- These are bring-up checks, not full `lit` tests yet.
- They only require `-filetype=asm`.
- If your `llc` binary points at a different LX32 source checkout, failures may
  reflect checkout mismatch rather than this workspace.

## Bare-Metal C smoke

Run:

```bash
bash /Users/axel/lx32/tools/lx32_backend/tests/baremetal/run_baremetal_smoke.sh
```

This validates the freestanding C path (`clang -> llc -march=lx32`) for:

- plain integer arithmetic,
- pointer/MMIO loads and stores,
- direct calls and returns,
- no implicit libcalls.

Current expected status: three PASS cases (`return42`, `call_chain`,
`pointer_store`) and one tracked XFAIL (`branch_loop`).

## What is still missing for executing C end-to-end

- `core/LX32FrameLowering.cpp` still has empty prologue/epilogue emission,
  so non-leaf calls do not preserve `ra` safely yet.
- MC/object emission for a full `-filetype=obj` pipeline is not complete in
  this workspace cut, so linking/running ELF binaries is not ready.



