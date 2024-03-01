import sys
def input():
    return sys.stdin.readline()


n = int(input())
m = list(map(int, input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(1,n):
	for j in range(n-i):
		dp[j][j+i] = sys.maxsize
		for k in range(i):
			dp[j][j+i] = min( dp[j][j+i], dp[j][j+k]+dp[j+k+1][j+i] + (m[j]*m[j+k+1]*m[j+i+1]) )
print(dp[0][n-1])
