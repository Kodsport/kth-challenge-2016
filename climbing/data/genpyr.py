#!/usr/bin/env python3

from sys import argv
n=int(argv[1])
print(n*(n+1)//2)
for i in range(n):
    print(0)
start=1
for i in range(1,n):
    for j in range(n-i):
        print(2,start+j,start+j+1)
    start+=(n-i+1)

print(n*(n+1)-1)
for i in range(1,n+1):
    print(i)
start=n+1
startdel=1
for i in range(1,n):
    for j in range(n-i):
        print(start+j)
    for j in range(n-i+1):
        print(startdel+j)
    start+=(n-i)
    startdel+=(n-i+1)
