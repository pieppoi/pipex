#!/bin/bash
set -e

echo "hello world" > infile.txt

# テスト1: cat -> grep
./pipex infile.txt "cat" "grep hello" outfile.txt
if grep -q "hello" outfile.txt; then
    echo "Test 1 OK"
else
    echo "Test 1 FAIL"
fi

# テスト2: tr -> wc
./pipex infile.txt "tr a-z A-Z" "wc -w" outfile2.txt
if grep -q "2" outfile2.txt; then
    echo "Test 2 OK"
else
    echo "Test 2 FAIL"
fi

rm -f infile.txt outfile.txt outfile2.txt