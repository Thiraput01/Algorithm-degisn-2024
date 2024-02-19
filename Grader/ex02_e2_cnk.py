n, k = map(int, input().split())
dp = [[1 for _ in range(n+1)] for _ in range(k+1)]
for i in range(1, k+1):
    for j in range(i, n+1):
        if i==j:
            continue
        dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
print(dp[k][n])
        
            