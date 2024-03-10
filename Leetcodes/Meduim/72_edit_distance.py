def solve(word1, word2):
    n = len(word1)
    m = len(word2)
    memo = {}
    def dfs(i1, i2):
        if i1 >= n:
            #ex word1 : "a"
            #	word2 : "abc"
            #i1 = 1, i2 = 1
            #need to insert 2 or m - i2 
            return m - i2
        if i2 >= m:
            #ex word1 : "abc"
            #	word2 : "a"
            #i1 = 1, i2 = 1
            #need to delete 2 or n - i1
            return n - i1
            
        if (i1, i2) in memo:
            return memo[(i1, i2)]
        
        if word1[i1] == word2[i2]:
            memo[(i1, i2)] = dfs(i1+1, i2+1)
        else:
            #all need +1 for ans
            
            #insert i, j+1
            insert = dfs(i1, i2+1)
            #erase i+1, j
            erase = dfs(i1+1, i2)
            #replace i+1, j+1
            replace = dfs(i1+1, i2+1)
            
            memo[(i1, i2)] = 1 + min(insert, erase, replace)
        return memo[(i1, i2)]
    
    return dfs(0, 0)
#testcases
#word1 = "horse"; word2 = "ros"
word1 = "intention"; word2 = "execution"
print(solve(word1, word2))


