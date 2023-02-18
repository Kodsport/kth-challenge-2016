#!/usr/bin/env python3

from sys import argv
n=int(argv[1])
print(n)
print(0)
for i in range(2,n+1):
    print(1,i-1)
print(2*n-2)
print(1)
for i in range(2,n):
    print(i)
    print(i-1)
print(n)
