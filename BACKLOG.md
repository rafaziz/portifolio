# Portfolio Backlog

Tracked improvements and planned work.

## Planned
- [ ] **Add the `ia-backpropagation` project** to this portfolio and the gh-pages site.
      (The current "Number-Reading ANN" card is a placeholder for this — wire it to the real repo.)
- [ ] **Create a separate repository for a fault-injection system.** _(later)_

## From the code review (see CODE_REVIEW.md)
- [ ] Rewrite `d9` (swordfish) and `d11` (skyscraper) correctly and re-enable them in `main`.
- [ ] Rewrite `d8` (xy-wing) — `verifica()` counts 0==0 entries, so it never fires.
- [ ] `hybridMLsystem.py`: eliminate test-set leakage (PSO fitness + stacking fit on test) with a train/val/test split.
- [ ] `tic-tac-toe.c`: replace the 8-branch win-check staircase with a loop over line triplets; event-driven redraw instead of busy-wait; implement the minimax mode.
- [ ] Full audit of `upecman.c` (1,300 lines — only spot-checked).

## Suggested polish (from portfolio review)
- [ ] Add real screenshots / terminal GIFs for the C games (asciinema works well).
- [ ] Ship the `tic-tac-toe` minimax single-player mode, or keep it labelled "in progress".
- [ ] Add a per-project `README.md` to `upecman/` and the root `tic-tac-toe`.
- [ ] Commit a small sample `petr4data.txt` (or a fetch script) so `hybridMLsystem.py` runs out of the box.
- [ ] Refactor `hybridMLsystem.py` into functions + a `if __name__ == "__main__":` guard.
- [ ] Add a link to a CV/résumé and a photo on the site.
- [ ] Consider renaming the repo `portifolio` → `portfolio` (URL change; optional).
