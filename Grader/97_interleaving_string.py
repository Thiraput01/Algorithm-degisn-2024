# def solve(s1, s2, s3):
#     dp = {}
#     #i3 = i1 + i2
#     valid = len(s3) == len(s1) + len(s2)
#     def dfs(i1, i2):
#         if i1 >= len(s1) and i2 >= len(s2):
#             return True
#         if (i1, i2) in dp:
#             return dp[(i1, i2)]
#         
#         #if i1 from s1 match
#         if i1 < len(s1) and s1[i1] == s3[i1+i2] and dfs(i1+1, i2):
#             return True
#         #if i2 from s2 match
#         if i2 < len(s2) and s2[i2] == s3[i1+i2] and dfs(i1, i2+1):
#             return True
#         dp[(i1, i2)] = False
#         return False
#     
#     return dfs(0, 0) if valid else False
        
def solve(s1, s2, s3):
    n = len(s1)
    m = len(s2)
    l = len(s3)
    if l != n+m:
        return False
    dp = [[False for _ in range(m+1)] for _ in range(n+1)]
    dp[n][m] = True
    for i1 in range(n, -1, -1):
        for i2 in range(m, -1 , -1):
            #if i1 from s1 match
            if i1 < len(s1) and s1[i1] == s3[i1+i2] and dp[i1+1][i2]:
                dp[i1][i2] = True
            #if i2 from s2 match
            if i2 < len(s2) and s2[i2] == s3[i1+i2] and dp[i1][i2+1]:
                dp[i1][i2] = True
    return dp[0][0]
    
s1 = input()
s2 = input()
s3 = input()
print(solve(s1, s2, s3))



