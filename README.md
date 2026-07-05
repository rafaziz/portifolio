# Portfolio — Rafael Aziz da Silva Rocha

A collection of open-source projects I've built and maintained, in **C** and **Python** —
from terminal games written with `ncurses` to machine-learning systems. **Control &
Automation engineer** (POLI-UPE, graduating 2026, with international academic experience
at Politecnico di Torino), working in **Industrial DevOps** — bridging the factory floor
and the cloud.

🌐 **Live site:** https://rafaziz.github.io/portifolio/
🔗 [LinkedIn](https://www.linkedin.com/in/rafaziz) · ✉️ rafaelazizlvr@gmail.com

---

## Projects in this repository

| Project | Language | What it is |
|---|---|---|
| [Upecman](upecman/) | C · ncurses | Terminal Pac-Man clone with per-ghost AI, pre-move input buffer, level scaling |
| [Tic-Tac-Toe](tic-tac-toe.c) | C · ncurses | Colour terminal tic-tac-toe with score tracking (minimax AI in progress) |
| [Sudoku Solver](sudoku-solver/) | C | Constraint-propagation solver reading puzzles from stdin |
| [Hybrid ML System](hybridMLsystem.py) | Python | AR + neural-net + PSO-tuned SVM ensemble for stock-price forecasting |

> Other projects (handwritten-digit **ANN in C**, **Arcadia** user-registry sim) live in
> separate repositories on [my GitHub](https://github.com/rafaziz).

---

## Build & run

### C projects (Linux / WSL / macOS)
These use the `ncurses` library. Install it first (`sudo apt install libncurses-dev`).

```bash
# Tic-Tac-Toe
gcc tic-tac-toe.c -o tic-tac-toe.x -lncurses -lm -Wall -Wextra
./tic-tac-toe.x

# Upecman
cd upecman && make && ./upecman.x

# Sudoku Solver
cd sudoku-solver && make
./sudoku999.x < sudoku-input-001.txt
```

### Hybrid ML System (Python 3.9+)
```bash
pip install -r requirements.txt
# place a CSV named petr4data.txt (with a "Close" column) in this folder, then:
python hybridMLsystem.py
```

---

## License
Released under the **GNU GPL v2** unless a project states otherwise. See [LICENSE](LICENSE).
