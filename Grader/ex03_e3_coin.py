n, m = map(int, input().split())
c = list(map(int, input().split()))
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
for j in range(1, m+1):
    dp[0][j] = 10001
    
for i in range(1, n+1):
    for j in range(1, m+1):
            
        if c[i-1] > j:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = min(dp[i][j-c[i-1]] + 1, dp[i-1][j])

print(dp[-1][-1] if dp[-1][-1] != 10001 else -1)
