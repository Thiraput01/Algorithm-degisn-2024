# def solve(amount, coins):
#     n = len(coins)
#     memo = {}
#     def dfs(i, target):
#         if i >= n:
#             return 0
#         if target == 0:
#             return 1
#         if target < 0:
#             return 0
#         
#         if (i, target) in memo:
#             return memo[(i, target)]
#         #                        use coin                 not use
#         memo[(i, target)] = dfs(i, target-coins[i]) + dfs(i+1, target)
#         return memo[(i, target)]
#     
#     return dfs(0, amount)

def solve(amount, coins):
    n = len(coins)
    dp = [[0 for _ in range(amount+1)] for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1
    
    for i in range(1, n+1):
        for j in range(1, amount+1):
            if j - coins[i-1] >= 0:
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][amount]
    
amount = int(input())
coins = [*map(int, input().split())]
print(solve(amount, coins))

