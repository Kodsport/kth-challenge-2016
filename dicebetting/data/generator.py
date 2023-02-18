#!/usr/bin/env python3
import random
import sys
from sys import stdin


t = stdin.readline().strip().split()
if t[0] == "exactly":
    n, s = int(t[1]), int(t[2])
else:
    n = random.randint(int(t[1]), int(t[2]))
    s = random.randint(int(t[3]), int(t[4]))

k = random.randint(0, s)

print(n, s, k)
