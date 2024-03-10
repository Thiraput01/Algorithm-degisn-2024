import sys
def input():
    return sys.stdin.readline()


n = int(input())
m = list(map(int, input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]
for d in range(1,n):
    for i in range(n-d):
        j = i + d
        dp[i][j] = min( [dp[i][k] + dp[k+1][j] + m[i-1]*m[k]*m[j]
                         for k in range(i, j)] )
print(dp[0][n-1])
