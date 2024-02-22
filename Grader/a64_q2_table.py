n = int(input())
n -= 2
dp = [0] * (n+1)
last_row1 = [0] * (n+1)
last_row2 = [0] * (n+1)
dp[0] = 7
last_row1[0] = 5
last_row2[0] = 5
for i in range(1, n+1):
    dp[i] = dp[i-1] + last_row1[i-1] + last_row2[i-1]
    last_row1[i] = last_row1[i-1] + (i + 2)
    last_row2[i] = last_row2[i-1] + (i + 2)
print(dp)
