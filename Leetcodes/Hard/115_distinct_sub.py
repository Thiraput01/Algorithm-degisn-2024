def solve(s, t):
    n = len(s)
    m = len(t)
    memo = {}
    # i: index of s
    # j: index of t
    def dfs(i, j):
        if j == m:
            #successfully matched
            return 1
        if i == n:
            return 0
        if (i, j) in memo:
            return memo[(i, j)]
        
        if s[i] == t[j]:
            memo[(i, j)] = dfs(i+1, j+1) + dfs(i+1, j)
        else:
            memo[(i, j)] = dfs(i+1, j)
        
        return memo[(i, j)]
    return dfs(0, 0)
        
        
        
#testcases
s = "rabbbit"; t = "rabbit"
#s = "babgbag"; t = "bag"
print(solve(s, t))
