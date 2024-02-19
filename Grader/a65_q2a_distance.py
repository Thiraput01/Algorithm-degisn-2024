n, k = map(int, input().split())
dp = [0] * (n+1)
mod = 100000007
dp[0] = 1
tmp = 0
for i in range(1, n+1):
    if i <= k:
        tmp = 1
    else:
        tmp = dp[i-k]
    dp[i] = dp[i-1] + tmp
print(dp[-1]%mod)