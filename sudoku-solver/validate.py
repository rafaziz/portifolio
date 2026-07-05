import sys, glob, os
def valid(grid):
    for i in range(9):
        row=[grid[i][j] for j in range(9)]
        col=[grid[j][i] for j in range(9)]
        if sorted(row)!=list(range(1,10)) or sorted(col)!=list(range(1,10)): return False
    for bi in range(3):
        for bj in range(3):
            blk=[grid[bi*3+a][bj*3+b] for a in range(3) for b in range(3)]
            if sorted(blk)!=list(range(1,10)): return False
    return True
def respects(grid, inp):
    return all(inp[i][j]==0 or inp[i][j]==grid[i][j] for i in range(9) for j in range(9))
home=sys.argv[1]
for i in [f"{n:03d}" for n in range(1,11)]:
    ef=os.path.join(home,f"{sys.argv[2]}_err_{i}.txt")
    inp=[[int(c) for c in l.strip()[:9]] for l in open(f"/mnt/f/portifolio/sudoku-solver/sudoku-input-{i}.txt") if l.strip()][:9]
    try:
        lines=[l.strip() for l in open(ef) if l.strip() and all(c.isdigit() for c in l.strip()[:9])][:9]
        g=[[int(c) for c in l[:9]] for l in lines]
        if len(g)!=9: print(i,"MALFORMED stderr"); continue
        zeros=sum(r.count(0) for r in g)
        print(i, "SOLVED-VALID" if (zeros==0 and valid(g) and respects(g,inp)) else f"FAIL (zeros={zeros}, valid={zeros==0 and valid(g)}, respects={respects(g,inp)})")
    except Exception as e: print(i,"ERR",e)
