import sys
def input():
    return sys.stdin.readline()
X = lambda:[*map(int, input().split())];n, m = X();v = X();nums = X()
for num in nums:
    c = 0
    for i in v:
        if i == num:
            break
        if i > num:
            c += 1
    print(c)