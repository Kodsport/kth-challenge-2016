#!/usr/bin/env python3

import math
import os

s = os.read(0, 1000000)
if s == b"0\n": print("0")
else:
    numlen = max(0, len(s) - 7)
    s = int(s)
    while True:
        nm = (numlen + 1) * 10 ** numlen
        if nm > s: break
        numlen += 1

    os.write(1, str(s//numlen).encode('ASCII'))
