#!/usr/bin/env python3

from sys import stdin

vv = ["PCC", "PPC", "PCP", "CPC"]
vsort = {"PCC":"CCP","PPC":"CPP","PCP":"CPP","CPC":"CCP"}

def is_sorted(s):
    return "PC" not in s

def solution(s):
    ans=0
    while not is_sorted(s):
        for p in vv:
            if p in s:
                s=s.replace(p,vsort[p],1)
                break
        ans+=1
    return ans

print(solution(stdin.readline()[0:-1]))
