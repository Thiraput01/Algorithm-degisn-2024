memo = {}

def sol(coins, target):
    if target in memo:
        return memo[target]
    if target == 0:
        ans = 0
    else:
        ans = 100001
        for coin in coins:
            if target - coin >= 0:
                ans = min(sol(coins, target - coin)+1, ans)
    memo[target] = ans
    return ans

n, m = map(int, input().split())
v = list(map(int, input().split()))
print(sol(v,  m))