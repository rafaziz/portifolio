# Code Review — July 2026

Full technical review of the portfolio projects: bugs found, fixes applied, and what
remains. All sudoku fixes were **verified by compiling and running the 10 sample
puzzles** (WSL/gcc) with an independent Python validator (`sudoku-solver/validate.py`).

## sudoku-solver — before: solved 2/10 puzzles · after: **10/10, "extreme" in 0.1 s**

### Fixed (verified by tests)
| # | Bug | Effect |
|---|-----|--------|
| 1 | `tenta8()` (backtracking) always `return 1`, even on dead ends | Search never backtracked properly — 8/10 puzzles left unsolved cells |
| 2 | `tenta8()` reset failed cells to *all* candidates instead of restoring the deduced set | Corrupted state after backtrack |
| 3 | `clap()` cleared `w[l][c][d+1]` instead of `[d]` | Removed the *wrong* candidate + out-of-bounds write at d=8 |
| 4 | `pode()` block check: `fd` accumulated across cells (reset per row, not per cell) | Missed conflicts → could accept invalid digits |
| 5 | `main` returned `check()` (1 on success) | Exit code inverted vs. documented convention |
| 6 | stderr echo of the solution (promised in README) never implemented | Added `printraw()` |
| 7 | `entrada()` didn't validate input | Out-of-bounds write on malformed/short lines |
| 8 | `d2b` hidden-single block loops used bounds `0..ls+3` (and `ls` for columns) | Compared against cells outside the block → wrong deductions |
| 9 | `d3b` naked-pair block loops had wrong bounds and could pair cells of different blocks; same-row/column pairs never enumerated | Wrong/missed eliminations |
| 10 | `removepairb()` inner loop typo `for(d2=0;d<2;d++)` (increments outer `d`) | Block pair removal mostly a no-op |
| 11 | `d4l/d4c/d4b` hidden pair: compared candidates with `==` (true for 0==0 → false pairs), passed 0-based indices to `limparCelula` (expects 1-based digits), read `w[..][..][9]` out of bounds, skipped digit 1, checked only cells *after* the pair, `fc` used uninitialized | Catastrophic wrong eliminations |
| 12 | `d5l/d5c` pointing pair: only checked block lines *after* the current one | False positives → wrong removals |
| 13 | `d7l/d7c` x-wing: same "only checks after" flaw + `fcounter` uninitialized on empty range | False x-wings |
| 14 | Deduction results overwritten (`z =`) instead of accumulated (`z +=`) in `d1*`, `d3*`, `d5*`, `d6*` | Main loop could stop while progress was still being made |
| 15 | `skyscraper()` matched `0==0` and reported progress on no-op removals | False progress (infinite-loop risk once z was accumulated) |
| 16 | `check()` verified only *completeness*, not validity | Added `valido()` (row/col/block rule check), used in exit code |
| 17 | No recovery path if a deduction corrupted the grid | Added safety net in `main`: snapshot of initial state + pure backtracking retry |

### Deliberately disabled (documented, not deleted)
- **`d9` (swordfish)** and **`d11` (skyscraper)**: the implementations have structural
  false positives (incomplete "only two cells" verification, dubious removal targets).
  With them enabled, corrupted grids forced exhaustive failed searches (test 010 timed
  out at 30 s). Disabled in `main`; the fixed backtracking covers those puzzles
  (010 now solves in 0.107 s). Rewriting them correctly is in the backlog.
- **`d8` (xy-wing)** is currently a no-op: `verifica()` counts equal *entries* (including
  0==0 pairs) so the "exactly one shared candidate" condition never holds. Harmless;
  rewrite in backlog.

### Test suite
```bash
cd sudoku-solver
bash run-tests.sh mytag          # compiles + runs the 10 sample puzzles (WSL/Linux)
python3 validate.py ~/sudotest mytag   # independently validates every solution
```

## tic-tac-toe.c
- **Fixed:** missing `#include <unistd.h>` (usleep was an implicit declaration — UB, breaks with `-Werror`).
- **Fixed:** after "play again", the cursor kept drawing the last played piece (`ch` not reset).
- Known (backlog): busy-wait render loop (`timeout(0)` + `usleep`), the 8 win conditions are a
  deeply-nested `else-if` staircase begging for a loop over line triplets, and the promised
  minimax single-player mode does not exist yet.

## hybridMLsystem.py
- **Fixed:** `.as_matrix()` (removed from pandas in 2021) → `.to_numpy()` — the script did not run at all.
- **Fixed:** PSO returned the final model built from `pop[index]` (a particle's *current*
  position, which had already moved away) instead of `gbest` (best solution found).
- **Fixed:** `serie[251]` hardcoded index (breaks on any dataset ≠ 252 rows) → `serie.iloc[-1]`.
- Known (backlog): **PSO fitness is evaluated on the test set** — hyper-parameter tuning
  leaks test data; should use a validation split. The stacking regression (`coef`) is also
  fit on test predictions. Results are therefore optimistic; restructure with a proper
  train/val/test split. Local `MSE` variable in `RN()` shadows the imported function name.

## upecman
- Includes are correct (`unistd.h`, `time.h` present). Not fully audited (1,300 lines);
  targeted checks found no equivalent of the bugs above. Full audit in backlog.
