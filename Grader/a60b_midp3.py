MOD = 1997
n, k = map(int, input().split())
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
for i in range(1, n+1):
    dp[i][1] = 1
    for j in range(2, min(k+1, i+1)):
        dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j])*j) % MOD
print(dp[-1][-1])
