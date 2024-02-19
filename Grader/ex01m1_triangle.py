n = int(input())
v = []
for i in range(n):
    v.append(list(map(int, input().split())))

dp = [[0 for _ in range(n+1)]for _ in range(n)]
#set base
dp[0][1] = v[0][0]
#loop
ans = dp[0][1]
for i in range(1, n):
    for j in range(i+1):
        dp[i][j+1] = v[i][j] + max(dp[i-1][j], dp[i-1][j+1])
        if i == n-1:
            ans = max(ans, dp[i][j])

print(ans)