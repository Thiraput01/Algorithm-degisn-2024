_, __ = input().split()

st1 = input().strip()
st2 = input().strip()
    
st = ""
ans = ""
locked = False
dp = [[0 for _ in range(len(st1)+1)] for _ in range(len(st2)+1)]
for i in range(1, len(st2)+1):
    for j in range(1, len(st1)+1):
        if st2[i-1] == st1[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
            st += st2[i-1]
            
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])
            

# Backtrack to reconstruct the longest common substring
subsequence = ""
i, j = len(st2), len(st1)
while i > 0 and j > 0:
    if st2[i-1] == st1[j-1]:
        subsequence = st2[i-1] + subsequence
        i -= 1
        j -= 1
    elif dp[i-1][j] > dp[i][j-1]:
        i -= 1
    else:
        j -= 1
            
        
print(subsequence)

