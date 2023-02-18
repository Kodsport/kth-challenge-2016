#!/usr/bin/env python3
import sys

x = list(map(int, list(sys.stdin.read().strip())))
if x == [0]:
    print('0')
else:
    for L in range(len(x),0,-1):
        r = 0
        f = -1
        y = x[:]
        for i in range(len(x)):
            r = 10*r+x[i]
            y[i] = r//L
            if y[i] > 0 and f < 0:
                f = i
            r = r % L
        if r == 0 and len(x)-f == L:
            print(''.join(map(str, y[f:])))
            break
