def solve(days, costs):
    memo = {}
    n = len(days)
    trip = [1, 7, 30]
    def cal(idx):
        if idx == n:
            return 0
        if idx in memo:
            return memo[idx]
    
        memo[idx] = float("inf")
        for i in range(len(trip)):
            j = idx
            #move j to the next index of the list that does not get covered
            while j < len(days) and days[j] < days[idx]+trip[i]:
                j += 1
            memo[idx] = min(memo[idx], costs[i]+cal(j))
        return memo[idx]

    
    return cal(0)
        
days = [*map(int, input().split())]
costs = [*map(int, input().split())]
print(solve(days, costs))