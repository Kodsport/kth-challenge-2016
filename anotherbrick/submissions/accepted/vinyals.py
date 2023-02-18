#!/usr/bin/env python3

import sys
from sys import stdin

h,w,n = map(int,stdin.readline().split())
xx = map(int,stdin.readline().split())

ww=w
for x in xx:
    if x>ww:
        break
    ww-=x
    if ww==0:
        ww=w
        h-=1
        if h==0:
            print("YES")
            sys.exit(0)
print("NO")
