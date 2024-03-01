MOD = 1000003
n, k = map(int, input().split())
s = list(map(int, input().split()))
dp = [0] * (n+1)
for p in s:
    dp[p] = 1
for i in range(1, n+1):
    for p in s:
        if i-p >= 0:
            dp[i] = (dp[i] + dp[i-p]) % MOD
print(dp[-1])