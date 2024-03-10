n, m, k = map(int, input().split())
dp = [[[0 for _ in range(k+1)] for _ in range(m+1)] for _ in range(n+1)]
dp[1][1][0] = 1
# i: # of bars
# j: # of consecutive bars
# l: # to keep track of how many bars changed
for i in range(2, n+1):
    for j in range(1, m+1):  # Change the range to m+1
        for l in range(0, k+1):
            # Case 1: not changing color
            if j-1 >= 0:
                dp[i][j][l] += dp[i-1][j-1][l]
            # Case 2: changing color
            if l-1 >= 0:
                dp[i][1][l] += dp[i-1][j][l-1]
ans = 0
for i in range(1, m+1):  # Change the range to m+1 and start from 1
    ans += dp[n][i][k]
print(ans)
