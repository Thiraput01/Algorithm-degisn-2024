def solve(nums):
    memo = {}
    nums = [1] + nums + [1]
    n = len(nums)
    def dfs(l, r):
        if l > r:
            return 0
        
        if (l, r) in memo:
            return memo[(l, r)]
        
        ans = 0
        # try every index in range l to r
        for i in range(l, r+1):
            # Think in reverse: pop i at last
            coins = ( nums[i] * nums[r+1] * nums[l-1] ) + dfs(l, i-1) + dfs(i+1, r)
            ans = max(coins, ans)
        memo[(l, r)] = ans
        return ans
    return dfs(1, n-2)
        
        
nums = [*map(int, input().split())]
print(solve(nums))

