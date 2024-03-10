def solve(cost):
    
    #top down
#     memo = {}
#     n = len(cost)
#     def cal(i):
#         if i >= n:
#             return 0
#         if i in memo:
#             return memo[i]
#         money = min(cal(i+1)+cost[i], cal(i+2)+cost[i])
#         memo[i] = money
#         return memo[i]
#     return min(cal(0), cal(1))

    #bottom up
    dp = [0] * len(cost)
    dp[0], dp[1] = cost[0], cost[1]
    for i in range(2, len(cost)):
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
    return min(dp[-1], dp[-2])
    
        
cost = [*map(int, input().split())]
print(solve(cost))
