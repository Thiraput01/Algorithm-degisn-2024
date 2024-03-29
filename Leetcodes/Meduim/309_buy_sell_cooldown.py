def solve(prices):
    n = len(prices)
    memo = {}
    def cal(i, isBuy):
        if i >= n:
            return 0
        if (i, isBuy) in memo:
            return memo[(i, isBuy)]

        if isBuy :
            memo[(i, isBuy)] = max( cal(i+1, False) - prices[i],
                                    cal(i+1, True) )
        else:
            memo[(i, isBuy)] = max( cal(i+2, True) + prices[i],
                                    cal(i+1, False) )  
        return memo[(i, isBuy)]
    return cal(0, True)
        
            
prices = [*map(int, input().split())]
print(solve(prices))


