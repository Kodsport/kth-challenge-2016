#!/usr/bin/env python3

from random import randint

h=20
w=20

bricks=[]
for i in range(h):
    free=w
    while(free>10):
        brick=randint(1,10)
        bricks.append(brick)
        free-=brick
    bricks.append(free)

print(h,w,len(bricks))
print(" ".join(map(str,bricks)))
