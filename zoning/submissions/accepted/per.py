# Note: without pypy this will TLE!
import sys

n = int(sys.stdin.readline())
grid = [sys.stdin.readline() for _ in range(n)]

N = n*n
D = [N+1]*N
Q = [None]*N
qh = qt = 0
for i in range(n):
    for j in range(n):
        if grid[i][j] == '3':
            D[i*n+j] = 0
            Q[qh] = (i,j)
            qh += 1

maxd = 0
while qt < qh:
    (i,j) = Q[qt]
    d = D[i*n+j]
    if grid[i][j] == '1':
        maxd = max(maxd, d)
    qt += 1
    for (ni, nj) in ((i+1,j), (i, j+1), (i-1, j), (i, j-1)):
        if ni < 0 or nj < 0 or ni >= n or nj >= n or D[ni*n+nj] <= N:
            continue
        D[ni*n+nj] = d+1
        Q[qh] = (ni, nj)
        qh += 1

print(maxd)
