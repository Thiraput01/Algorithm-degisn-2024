import sys

n = int(input())
v = list(map(int, input().split()))
dp = [-sys.maxsize for _ in range(n)]
if n <= 3:
    print(sum([e for e in v if e >= 0]))
else:
    dp[0], dp[1], dp[2] = v[0], v[1], v[2]
    for i in range(1, n):
        dp[i] = max(dp[i-1], dp[i-2], dp[i-3]) + v[i]
    print(dp[-1])
        

