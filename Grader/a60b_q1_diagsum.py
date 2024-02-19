n = int(input())
A = []
for i in range(n):
    A.append(list(map(int, input().split())))
dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
cur_max = A[0][0]
for i in range(1, n+1):
    for j in range(1, n+1):
        if i == 1 or j == 1:
            dp[i][j] = A[i-1][j-1]
        else:
            dp[i][j] = max(A[i-1][j-1], A[i-1][j-1] + dp[i-1][j-1])
        cur_max = max(cur_max, dp[i][j])
print(cur_max)
            