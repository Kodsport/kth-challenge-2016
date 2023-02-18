import sys
import random

random.seed(42)


case_no = 1

def next_file(tag=None):
    global case_no
    tag = ('' if tag is None else '.'+tag).replace(' ', '_')
    outfile = '%02d%s.in' % (case_no, tag)
    case_no += 1
    return open(outfile, 'w')

def save_case(grid, tag):
    sys.stderr.write('saving case n %d\n' % len(grid))
    out = next_file(tag)
    out.write('%d\n' % len(grid))
    for r in grid:
        out.write('%s\n' % ''.join(r))
    out.close()


def ensure_all_types(grid):
    # make sure each type appears
    taken = set()
    n = len(grid)
    for i in '123':
        while True:
            r = random.randint(0, n-1)
            c = random.randint(0, n-1)
            if (r, c) not in taken:
                break
        grid[r][c] = i
        taken.add((r,c))

def rand_grid(n, choices):
    return [[random.choice(choices) for _ in range(n)] for _ in range(n)]

def biased_case(n, f1, f2, f3):
    grid = rand_grid(n, '1'*f1 + '2'*f2 + '3'*f3)
    ensure_all_types(grid)
    save_case(grid, 'rand %d %d %d %d' % (n, f1, f2, f3))
    
def uniform_case(n):
    biased_case(n, 1, 1, 1)

def mostly_x(n, x):
    grid = rand_grid(n, x)
    ensure_all_types(grid)
    save_case(grid, 'mostly%c %d' % (x, n))

def max_ans(n):
    grid = rand_grid(n, '2')
    grid[n-1][0] = '1'
    grid[0][n-1] = '3'
    save_case(grid, 'maxans %d' % (n))

def checker(n):
    grid = rand_grid(n, '1')
    for i in range(n):
        for j in range(i % 2, n, 2):
            grid[i][j] = '3'
    save_case(grid, 'checker %d' % (n))

def stripe(n, a1, b1, c1, a3, b3, c3):
    grid = rand_grid(n, '2')
    for i in range(n):
        for j in range(n):
            if a1*i+b1*j + c1 > 0:
                grid[i][j] = '1'
            elif a3*i+b3*j + c3 > 0:
                grid[i][j] = '3'
    save_case(grid, 'stripe %d' % (n))

# MAXN 1500

uniform_case(100)

for i in range(5):
    n = random.randint(2, 1500)
    f1 = random.randint(1, 100)
    f2 = random.randint(1, 100)
    f3 = random.randint(1, 100)
    biased_case(n, f1, f2, f3)

uniform_case(1500)
biased_case(1500, 1, 90, 9)
biased_case(1500, 9, 90, 1)

mostly_x(1234, '1')
mostly_x(1412, '2')
mostly_x(1499, '3')

checker(1500)
max_ans(1500)


# 1s: x < 500 + y/250 <=> -x + y/250 + 500 > 0
# 3s: x > 1000 + y/250 <=> x -y/250 - 1000 > 0
stripe(1500,
       -1, 1.0/250, 500, 
       1, -1.0/250, -1000)

# 1s: y < -1500+2*x <=> 2x -y - 1500 > 0
# 3s: x < 700 - y/10 <=> -x -y/10 + 700 > 0
stripe(1500,
       2, -1, -1500,
       -1, -0.1, 700)


