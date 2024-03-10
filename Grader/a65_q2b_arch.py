import sys

def input():
    return sys.stdin.readline()

def perform(l, r):
    if l >= r:
        return 0
    if dp[l][r] == sys.maxsize:
        res = 0
        #use pair l, r
        res = perform(l+1, r-1) + v[l] * v[r]
        #not use pair l, r => calculate all possible from l to r
        for i in range(l+1, r):
            res = max(res, perform(l, i) + perform(i+1, r))
        dp[l][r] = res
    return dp[l][r]

n = int(input())
dp = [[sys.maxsize] * 501 for _ in range(501)]
v = [0] + list(map(int, input().split()))

ans = perform(1, n)
print(ans)

