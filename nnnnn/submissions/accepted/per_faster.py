#!/usr/bin/env python3
import sys

x = list(map(int, list(sys.stdin.read().strip())))
if x == [0]:
    print('0')
else:
    L = -1
    r = 0
    for i in range(len(x)):
        r = 10*r+x[i]
        if L == -1 and r >= len(x)-i:
            L = len(x)-i
        if L > 0:
            x[i] = r // L
            r = r % L
    print(''.join(map(str, x[-L:])))

