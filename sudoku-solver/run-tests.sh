#!/bin/bash
# usage: bash run-tests.sh <tag>  — compiles sudoku999.c and runs the 10 sample puzzles
cd /mnt/f/portifolio/sudoku-solver
TAG=$1
mkdir -p ~/sudotest
gcc sudoku999.c -o ~/sudotest/sudoku_$TAG.x -Wall -Wextra 2> ~/sudotest/build_$TAG.log
echo "build rc=$? warnings: $(wc -l < ~/sudotest/build_$TAG.log)"
for i in 001 002 003 004 005 006 007 008 009 010; do
  timeout 30 ~/sudotest/sudoku_$TAG.x < sudoku-input-$i.txt > ~/sudotest/${TAG}_out_$i.txt 2> ~/sudotest/${TAG}_err_$i.txt
  echo "$i rc=$?"
done
