#!/usr/bin/env bash
set -euo pipefail

ROOT="/Users/axel/lx32/tools/lx32_backend/tests"
PROGRAM_DIR="$ROOT/baremetal/programs"
COMPILE_SH="$ROOT/compile_baremetal_c.sh"

if [[ ! -x "$COMPILE_SH" ]]; then
  chmod +x "$COMPILE_SH"
fi

check_one() {
  local c_file="$1"
  local stem
  stem="$(basename "$c_file" .c)"
  local out_prefix="/tmp/lx32_${stem}"

  echo "==> $stem"
  "$COMPILE_SH" "$c_file" "$out_prefix"

  local asm_file="${out_prefix}.s"
  local ll_file="${out_prefix}.ll"

  if grep -Eq "__[a-z0-9_]+(si3|di3)|memcpy|memset|memmove" "$asm_file" "$ll_file"; then
    echo "FAIL $stem: runtime/libcall dependency detected" >&2
    return 1
  fi

  if ! grep -Eiq "ret|jalr" "$asm_file"; then
    echo "FAIL $stem: missing return instruction in asm" >&2
    return 1
  fi

  if [[ "$stem" == "03_call_chain" ]] && ! grep -Eiq "call|jalr|jal" "$asm_file"; then
    echo "FAIL $stem: missing call-like instruction sequence in asm" >&2
    return 1
  fi

  if [[ "$stem" == "04_branch_loop" ]] && ! grep -Eiq "beq|bne|blt|bge|jal" "$asm_file"; then
    echo "FAIL $stem: missing branch/loop-like instruction sequence in asm" >&2
    return 1
  fi

  echo "PASS $stem"
}

check_expected_fail() {
  local c_file="$1"
  local stem
  stem="$(basename "$c_file" .c)"
  local out_prefix="/tmp/lx32_${stem}_xfail"

  echo "==> $stem (expected-fail for now)"
  if "$COMPILE_SH" "$c_file" "$out_prefix" >/tmp/lx32_${stem}_xfail.log 2>&1; then
    echo "FAIL $stem: expected current backend to fail this case" >&2
    return 1
  fi

  if ! grep -Eq "Cannot select|Abort trap|LLVM ERROR" "/tmp/lx32_${stem}_xfail.log"; then
    echo "FAIL $stem: failure did not match known selector gap" >&2
    cat "/tmp/lx32_${stem}_xfail.log"
    return 1
  fi

  echo "XFAIL $stem"
}

check_one "$PROGRAM_DIR/01_return42.c"
check_one "$PROGRAM_DIR/03_call_chain.c"
check_one "$PROGRAM_DIR/02_pointer_store.c"
check_expected_fail "$PROGRAM_DIR/04_branch_loop.c"

echo "bare-metal C smoke tests passed"



