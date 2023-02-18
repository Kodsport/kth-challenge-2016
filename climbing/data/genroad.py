#!/usr/bin/env python3

from sys import argv
n=int(argv[1])
w=int(argv[2])

print(n*w)
for j in range(w):
    print(0)
for i in range(n-1):
    for j in range(w):
        print(2,i*w+j+1,i*w+(j+1)%w+1)

print(2*w*(n-1))
for j in range(w):
    print(j+1)
for i in range(1,n-1):
    for j in range(w):
        print(i*w+j+1)
    for j in range(w):
        print((i-1)*w+j+1)
for j in range(w):
    print((n-1)*w+j+1)
