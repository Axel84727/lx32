# Bare-Metal C Smoke (LX32)

This folder validates the minimum C-freestanding slice for firmware/drivers on LX32:

- assignments and integer arithmetic,
- raw pointer/MMIO loads and stores,
- control flow and direct calls,
- no libc/runtime dependency.

## Programs

- `programs/01_return42.c` - simplest entrypoint.
- `programs/02_pointer_store.c` - pointer dereference load/store.
- `programs/03_call_chain.c` - direct call sequence and return path.
- `programs/04_branch_loop.c` - simple counted loop with branches (currently `XFAIL`).

## Run

```bash
bash /Users/axel/lx32/tools/lx32_backend/tests/baremetal/run_baremetal_smoke.sh
```

## Notes

- Uses `-ffreestanding -fno-builtin -nostdlib`.
- `tests/compile_baremetal_c.sh` always emits `.ll` and `.s`.
- `.o` is attempted and reported as best-effort while MC object emission is
  still being finished.
- Script fails if it detects common libcalls (`__divsi3`, `memcpy`, etc.).
- `04_branch_loop.c` is tracked as expected-fail until branch lowering
  (`br`/`brcond`) is completed in the LX32 lowering/selector path.



