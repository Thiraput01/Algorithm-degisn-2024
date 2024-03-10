def solve(prices):
    n = len(prices)
    l, r = 0, 1 #buy, sell
    ans = 0
    while r < n:
        if prices[l] < prices[r]:
            pf = prices[r] - prices[l]
            ans = max(ans, pf)
        else:
            #find l that lower that the lowest
            l = r
        r += 1
    return ans
prices = [*map(int, input().split())]
print(solve(prices))

