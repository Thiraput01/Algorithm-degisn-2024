import sys

memo = {}

def gaa(n):
    #base case : g(0) = gaa
    if n <= 3: 
        return 'g' if n == 1 else 'a'
    #if already seen : return
    if n in memo:
        return memo[n]
    k = 0
    g = 3
    g_1 = 0 #this is g(k-1)
    
    while g < n:
        g_1 = g
        k += 1
        g = 2 * g + (k + 3)
    
    #now we got g(k-1) --> we need to check that after g(k-1) + (k+3) its exceeded n or not
    #if yes, minus n with g(k-1) + (k+3)
    #if no, its mean n is in this range --> then if n - g(k-1) = 1 means its 'g' on gaa
    if n <= g_1 + (k + 3):
        #ex n = 11; k = 2, g(k-1) = g a a g a a a g a a
        #since len(g(k-1)) = 10 means 11 is the first g at the g(k)
        memo[n] = 'g' if n - g_1 == 1 else 'a'
    else:
        memo[n] = gaa(n - (g_1 + (k + 3)))
    
    return memo[n]

print(gaa(int(sys.stdin.readline())))
