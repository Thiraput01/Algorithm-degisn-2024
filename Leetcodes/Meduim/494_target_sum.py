def solve(nums, target):
    memo = {}
    stop = len(nums)
    def cal(idx, total):
        if idx == stop:
            return 1 if total == target else 0
        if (idx, total) in memo:
            return memo[(idx, total)]
        #case 1 : +
        #case 2 : -
        memo[(idx, total)] = cal(idx+1, total+nums[idx]) + cal(idx+1, total-nums[idx])
        return memo[(idx, total)]
    return cal(0, 0)
    
nums = [*map(int, input().split())]
target = int(input())
print(solve(nums, target))