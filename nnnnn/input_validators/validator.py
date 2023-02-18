#!/usr/bin/env python3
import re
import sys

input_re = re.compile("^(0|[1-9][0-9]{0,999999})$")
inp = sys.stdin.readline()

assert input_re.match(inp)
assert len(sys.stdin.readline()) == 0
sys.exit(42)
