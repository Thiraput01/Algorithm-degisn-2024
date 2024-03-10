n = int(input())+1
dp = [[1, 2, 4] + [0] * (n - 3) for _ in range(n)]

# Calculate values using 2D dynamic programming
for i in range(3, n):
    dp[i][2] = (2 * dp[i - 1][2] - dp[i - 1][1] + dp[i - 1][0]) % 100000007
    dp[i][0], dp[i][1] = dp[i - 1][1], dp[i - 1][2]

print(dp[-1][2])
