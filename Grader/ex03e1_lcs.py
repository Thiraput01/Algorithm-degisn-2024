st1 = input()
st2 = input()
dp = [[0 for _ in range(len(st1)+1)] for _ in range(len(st2)+1)]
for i in range(1, len(st2)+1):
    for j in range(1, len(st1)+1):
        if st2[i-1] == st1[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])
print(dp[-1][-1])