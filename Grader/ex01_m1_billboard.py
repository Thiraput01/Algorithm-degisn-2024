n = int(input())
c = list(map(int, input().split()))
dp = [0] * (n+1)
dp[1] = c[0]
for i in range(2, n+1):
    dp[i] = max(dp[i-1], c[i-1]+dp[i-2])
print(dp[-1])