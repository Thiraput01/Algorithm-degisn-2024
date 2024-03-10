n, k = map(int, input().split())
v = list((map(int,input().split())))
dp = [10000001] * (n)
#init dp
for i in range(n):
    if i <= k:
        dp[i] = v[i]
    else:
        dp[i] = min(dp[i],min(dp[max(0,i-1-(k+k)):i])+v[i])
print(min(dp[-k-1:]))