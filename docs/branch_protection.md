# GitHub Branch Protection and CI Configuration Guide

This document explains how to configure GitHub to require all CI checks to pass before merging PRs to `main`.

## Workflow Overview

Three workflows are automatically triggered on each pull request to `main`:

1. **test-golden-model.yml** - Runs all 9 Rust golden model validation tests
2. **test-systemverilog.yml** - Runs all 9 SystemVerilog testbenches via Make
3. **ci.yml** - Master workflow that requires both above workflows to pass

## Setting Up Branch Protection

To enforce that PRs to `main` cannot be merged without passing CI:

### Step 1: Go to Repository Settings
1. On GitHub, go to your repository
2. Click on **Settings** tab
3. Select **Branches** from left sidebar

### Step 2: Add Branch Protection Rule

1. Click **Add rule**
2. Enter `main` in the **Branch name pattern** field
3. Enable the following protections:

#### Required Checks
- [x] **Require status checks to pass before merging**
  - Select these status checks:
    - `PR Gate - All Tests Required` (the master check)
    - Or individually:
      - `Golden Model Tests`
      - `SystemVerilog Testbenches`

#### Additional Protections (Recommended)
- [x] **Require a pull request before merging**
  - Reviews required: `1`
  - Dismiss stale pull request approvals when new commits are pushed: Yes
  - Require code review from code owners: Yes (if using CODEOWNERS)

- [x] **Require branches to be up to date before merging**
  - This ensures PR is tested against latest main

- [x] **Require status checks to pass before merging**
- [ ] **Require conversation resolution before merging**

#### Merge Restrictions (Optional)
- Allow squash merging: Yes
- Allow rebase merging: Yes
- Allow merge commits: No (enforces clean history)

- [x] **Restrict who can push to matching branches**
  - Allow: Admins and repository owners

- [x] **Require dismissal of stale reviews on new push**

### Step 3: Click **Create** or **Save changes**

## What Happens When a PR is Created

1. **Author creates PR** to `main`
2. **Workflows automatically trigger:**
   - `test-golden-model.yml` runs all 9 Rust tests in parallel
   - `test-systemverilog.yml` runs all 9 SystemVerilog testbenches in parallel
   - `ci.yml` waits for both and enforces gate
3. **Results appear on PR:**
   - Green ✅ checkmark = all tests passed, can merge
   - Red ❌ X = tests failed, cannot merge until fixed
4. **Author must fix failing tests** and push new commits
5. **Tests re-run automatically** on each push
6. **Once all pass**, merge button becomes available

## Workflow Details

### Golden Model Tests (test-golden-model.yml)

Runs in parallel:
- `test_alu` - ALU functionality (3000 iterations)
- `test_branch_unit` - Branch logic (10000 iterations)
- `test_control_unit` - Control signals (500 iterations)
- `test_imm_gen` - Immediate generation (2000 iterations)
- `test_lsu` - Memory operations (2000 iterations)
- `test_memory_sim` - Memory model (1000 iterations)
- `test_reg_generic` - Register template (2000 iterations)
- `test_register_file` - Register file (2000 iterations)
- `test_lx32_system` - Full system (500 iterations)

**Fails if:** Any single test module fails

### SystemVerilog Testbenches (test-systemverilog.yml)

Runs in parallel (via Makefile):
- `alu_tb` - ALU testbench
- `branch_unit_tb` - Branch unit testbench
- `control_unit_tb` - Control unit testbench
- `imm_gen_tb` - Immediate generator testbench
- `lsu_tb` - LSU testbench
- `memory_sim_tb` - Memory simulator testbench
- `reg_generic_tb` - Register generic testbench
- `register_file_tb` - Register file testbench
- `lx32_system_tb` - Full system testbench

**Fails if:** Any single testbench fails

### CI Gate (ci.yml)

Master workflow that:
1. Calls `test-golden-model.yml`
2. Calls `test-systemverilog.yml` 
3. Runs `pr-gate` job that waits for both
4. Reports overall status as **"PR Gate - All Tests Required"**

## Merging Behavior

With branch protection enabled:

| Scenario | Can Merge? | Why |
|----------|-----------|-----|
| All tests pass | ✅ Yes | All status checks green |
| One test fails | ❌ No | Status check red, blocks merge |
| Tests still running | ⏳ Pending | Cannot merge until complete |
| Author pushes fix | ✅ Tests re-run | New commit triggers workflows |
| Force push attempted | ❌ Rejected | Branch protection prevents it |

## Verifying Configuration

To verify branch protection is working:

1. When you create a test PR, you should see workflows running
2. In PR checks section, you'll see:
   - ⏳ Checks running (initial)
   - ❌ Checks failed (if test fails)
   - ✅ Checks passed (if all pass)
3. Merge button is grayed out until all pass

## Troubleshooting

### Workflows not running?
- Check `.github/workflows/` directory exists
- Verify `.yml` files are in that directory
- Check file syntax with `yamllint` locally

### Want to disable a test temporarily?
1. Edit the workflow file
2. Comment out the test from the `matrix.test` list
3. Push to feature branch (doesn't affect CI)
4. This won't block PRs

### Need to merge without passing tests?
1. Admins can dismiss failed status checks
2. Go to PR review section → dismiss checks
3. This logs the bypass for audit trail

### Making a workflow more permissive?
- Edit the workflow file
- Commit to `main` directly or via approved PR
- New runs use updated workflow

### Making a workflow stricter?
- Add new tests to the `matrix.test` list
- Only affects new PRs created after merge

## CI Performance

Expected run times:
- **Golden Model Tests:** 6-8 minutes (all 30,500 iterations)
- **SystemVerilog Testbenches:** 8-12 minutes (all 9 testbenches)
- **Total CI time:** ~15 minutes (runs in parallel)

**Cost:** Free (GitHub Actions provides 2000 free minutes/month for private repos)

## Examples

### Example PR Success
```
✅ Pull request checks
├── ✅ test-golden-model.yml (11 passed)
│   ├── ✅ test_alu
│   ├── ✅ test_branch_unit
│   ├── ... (all 9 modules)
│   └── ✅ All Tests Passed
├── ✅ test-systemverilog.yml (9 passed)
│   ├── ✅ alu_tb
│   ├── ✅ branch_unit_tb
│   ├── ... (all 9 testbenches)
│   └── ✅ All Testbenches Passed
└── ✅ PR Gate - All Tests Required

[Merge button AVAILABLE]
```

### Example PR Failure (one test fails)
```
✅ Pull request checks
├── ❌ test-golden-model.yml (8 passed, 1 failed)
│   ├── ✅ test_alu
│   ├── ❌ test_branch_unit (FAILED)
│   ├── ✅ test_control_unit
│   └── ... 
├── ⏳ test-systemverilog.yml (waiting)
└── ❌ PR Gate - All Tests Required (blocked)

[Merge button DISABLED]
Message: "1 check failed"
```

## Summary

This CI setup ensures:

1. ✅ **All tests run on every PR** - both Rust golden models and SystemVerilog testbenches
2. ✅ **Parallel execution** - faster feedback (both workflows run simultaneously)
3. ✅ **Fail-fast** - if any test fails, PR cannot merge
4. ✅ **Clear status** - developers see exactly which test failed
5. ✅ **Automated enforcement** - no manual oversight needed
6. ✅ **Audit trail** - all test runs logged in workflow history

Once configured, branch protection ensures `main` always contains code that passes all 18 test modules (9 Rust + 9 SystemVerilog).
