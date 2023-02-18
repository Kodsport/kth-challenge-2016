#!/usr/bin/env python3

import random
import sys

n=int(sys.argv[1])
random.seed(int(sys.argv[2]))
ds=[random.randint(1,10000) for i in range(n)]
ys=[-1]*(n+1)
for i in range(1,n+1):
    ys[i]=ys[i-1]+ds[i-1]
print(0,0,10000,ys[n]/10000)
print(n)
print(" ".join(map(str,(ys[i]/10000 for i in range(1,n)))))
print(" ".join(map(str,(random.randint(1,10000) for i in range(n)))))
