import sys

def input():
    return sys.stdin.readline()
def kadane(v, l, r):
    mss = -sys.maxsize
    cur = 0
    for i in range(l, r+1):
        cur += v[i]
        mss = max(cur, mss)
        cur = max(0, cur)
    
n = int(input())
v = list(map(int, input().split()))
d = {}
start = []
for i in range(len(v)):
    if v[i] in d:
        d[v[i]] += 1
        start.append(tmp)
    else:
        d[v[i]] = 1
        tmp = i

print(d)   
print(start)
