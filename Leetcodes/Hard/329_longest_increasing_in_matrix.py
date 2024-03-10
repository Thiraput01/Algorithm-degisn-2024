def solve(matrix):
    memo = {}
    n = len(matrix)
    m = len(matrix[0])
    # Use prev to check increasing
    def dfs(i, j, prev):
        if (i<0 or i>=n or
            j<0 or j>=m or
            matrix[i][j] <= prev):
            return 0
        
        if (i, j) in memo:
            return memo[(i, j)]

        res = max(1 + dfs( i+1, j, matrix[i][j] ),
                  1 + dfs( i-1, j, matrix[i][j] ),
                  1 + dfs( i, j+1, matrix[i][j] ),
                  1 + dfs( i, j-1, matrix[i][j]) )
        memo[(i, j)] = res
        return res
    
    longest = -1
    for i in range(n):
        for j in range(m):
            longest = max(longest, dfs(i, j, -1))
            
    return longest
#testcases
#matrix = [[1]]
matrix = [[3,4,5],[3,2,6],[2,2,1]]
print(solve(matrix))



