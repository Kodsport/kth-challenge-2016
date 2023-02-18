#!/usr/bin/env python3

from random import randint

h=100
w=100
n=10000

print(h,w,n)
print(" ".join(map(str,(randint(1,10) for i in range(n)))))
