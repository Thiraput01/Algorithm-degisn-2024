import sys
def input():
    return sys.stdin.readline()

n, m = map(int, input().split())
points = []
for i in range(n):
    l = list(map(int, input().split()))
    points.append(l)

dp = [[-sys.maxsize for _ in range(m+1)] for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, m+1):
        cp = points[i-1][j-1]
        if i == 1 and j == 1:
            dp[i][j] = cp
        else:
            dp[i][j] = max( dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + cp ) + cp            
print(dp[-1][-1])

