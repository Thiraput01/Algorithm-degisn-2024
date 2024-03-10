#Slow version, But good readablity
import sys

def input():
    return sys.stdin.readline()
 
n, m = map(int, input().split())
v = [0] * (n+1)
for i in range(n):
    v[i+1] = int(input())

dp = [[sys.maxsize for _ in range(m+1)] for _ in range(n+1)]
dp[0][0] = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        #find all subproblems from 1 to 101, and find the minimum of it
        subprob = [ (dp[i-1][j-k**2] + (v[i]-k)**2) for k in range(1, 101) if j-k**2 >= 0 ]
        dp[i][j] = min(subprob)
print(dp[n][m] if dp[n][m] != sys.maxsize else -1)
    