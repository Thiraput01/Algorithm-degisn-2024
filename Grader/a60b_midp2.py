n, a, b, c = map(int, input().split())
v = [a, b, c]
dp = [-1] * (n+1)
dp[0] = 0
for i in range(1, n+1):
    for j in v:
        if i-j >= 0 and dp[i-j] != -1:
            dp[i] = max(dp[i], dp[i-j] + 1)
print(dp[n])    
        
    
