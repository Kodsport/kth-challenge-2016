#!/usr/bin/env python3

from sys import argv
n=int(argv[1])
def seq(a,b):
    if a>b:
        return
    if a==b:
        yield b
        return
    mid=(a+b)//2
    for i in seq(a,mid): yield i
    for i in seq(mid+1,b): yield i
    for i in seq(a,mid): yield i

moves = list(seq(1,n))
print(len(moves))
for i in moves:
    print(i)
