#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
floating = integer + "?(\.\d+)?"
oneint = re.compile(integer + "\n")
string = re.compile("[1-3]+\n")

line = stdin.readline()
assert oneint.match(line)
n = int(line)
assert 2 <= n <= 1500

lines = []

for i in range(n):
    line = stdin.readline()
    assert string.match(line)
    assert len(line)==n+1
    lines.append(line)

lines = "".join(lines)

for c in ['1','2','3']:
    assert c in lines
    
assert len(stdin.readline()) == 0
sys.exit(42)
