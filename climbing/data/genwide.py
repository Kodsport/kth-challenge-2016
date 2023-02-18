#!/usr/bin/env python3

from sys import argv
n=int(argv[1])
print(n)
for i in range(n-1):
    print(0)
print (n-1," ".join(map(str,range(1,n))))
print(n)
for i in range(1,n+1):
    print(i)
