n = int(input())
v = [0] + list(map(int, input().split()))
dp = [1] * (n+1)
for i in range(n+1):
    subprob = [dp[k] for k in range(1, i) if v[k] < v[i]]
    dp[i] = 1 + max(subprob, default = 0)
    
print(max(dp)) 