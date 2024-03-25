import sys

def input():
    return sys.stdin.readline()

def dc(v, l, r, t, b, n):
    if n == 1:
        return v[l][t]
    m = n // 2
    for i in range(l+m, r):
        for j in range(t+m, b):
            if v[i][j] != 0:
                return 0
    p = dc(v,l,l+m,t,t+m, m)
    q = dc(v,l,l+m,t+m,b, m)
    r = dc(v,l+m,r,t,t+m, m)
    if(p==0 or q==0 or r==0):
        return 0
    if(p==q or p==r):
        return p
    if(q==r):
        return q
    return 0

for i in range(3):
    n = int(input())
    v = []
    for j in range(n):
        tmp = [*map(int, input().split())]
        v.append(tmp)
    print(dc(v, 0, n, 0, n, n))

