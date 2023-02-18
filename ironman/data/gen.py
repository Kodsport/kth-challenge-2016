#!/usr/bin/env python3

import random
import sys

n=10000
ds=[10000]*n
ys=[-1]*(n+1)
for i in range(1,n+1):
    ys[i]=ys[i-1]+ds[i-1]
print(0,0,10000,ys[n]/10000)
print(n)
v=[0.0001,10000]*5000
v=[10000]*10000
print(" ".join(map(str,(ys[i]/10000 for i in range(1,n)))))
print(" ".join(map(str,(v[i] for i in range(n)))))
