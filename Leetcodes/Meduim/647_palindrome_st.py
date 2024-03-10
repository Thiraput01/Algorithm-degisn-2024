def solve(s):
    n = len(s)
    res = 0
    for i in range(n):
        #odd length
        l, r = i, i
        while l>=0 and r<n and s[l] == s[r]:
            res += 1
            l -= 1
            r += 1
        #even length
        l, r = i, i+1
        while l>=0 and r<n and s[l] == s[r]:
            res += 1
            l -= 1
            r += 1
    return res
    
    

s = input()
print(solve(s))


