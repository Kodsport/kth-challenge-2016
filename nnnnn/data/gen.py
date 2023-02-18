#!/usr/bin/env python3

import sys
import random

tpe = sys.argv[1]
param = sys.argv[2]

if tpe == 'tenpow':
    param = int(param)
    print(str(param * 10**(param - 1)))

if tpe == 'tenpowminus1':
    param = int(param)
    print(str(param * (10**param - 1)))

if tpe == 'tenpowplus1':
    param = int(param)
    print(str(param * (10**(param - 1) + 1)))

if tpe == 'n':
    param = int(param)
    d = 0
    c = 1
    while param >= c:
        d += 1
        c *= 10
    print(param * d)

if tpe == 'd':
    param = int(param)
    print(param * random.randint(10 ** (param - 1), 10 ** param - 1))
