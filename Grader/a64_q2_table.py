mod = 100000007
n = int(input())

# Create dp list with separate lists for each row
dp = [1]*(n+1)
# Base case
# n = 1 --> [00] [01] [10]
dp[1] = 3
# From 2 to n
for i in range(2, n+1):
    dp[i] = (((2 * dp[i-1]) % mod) + dp[i-2]) % mod
    
print(dp[-1] % mod)


