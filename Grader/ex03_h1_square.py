r, c = map(int, input().split())
mt = []
for i in range(r):
    tmp = []
    for st in input().strip():
        tmp.append(int(st))
    mt.append(tmp)
    
dp = [[0 for _ in range(c+1)] for _ in range(r+1)]
ans = 0
dp[1][1] = mt[0][0]
for i in range(1, r+1):
    for j in range(1, c+1):
        if mt[i-1][j-1] == 1:
            dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
            
        ans = max(ans, dp[i][j])
        
print(ans)
            
        