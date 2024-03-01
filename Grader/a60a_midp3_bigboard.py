import sys

def input():
    return sys.stdin.readline()

n = int(input())
c = [*map(int, input().split())]
dp = [0] * (n+1)
dp[1], dp[2] = c[0], c[1]
for i in range(3, n+1):
    dp[i] = max(dp[i-1], c[i-1]+dp[i-3])
print(dp[-1])
