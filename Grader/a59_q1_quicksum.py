def solve(p, r1, c1, r2, c2):
    return p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1]

n, m, k = map(int, input().split())
mt = []
for i in range(n):
    mt.append(list(map(int, input().split())))
    
#make prefix sum for mt
p = [[0 for _ in range(m+1)] for _ in range(n+1)]
p[0][0] = mt[0][0]
for j in range(1, m):
    p[0][j] = p[0][j-1] + mt[0][j]
for i in range(1, n):
    p[i][0] = p[i-1][0] + mt[i][0]
    for j in range(1, m):
        p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + mt[i][j] 

for i in range(k):
    r1, c1, r2, c2 = map(int, input().split())
    print(solve(p, r1, c1, r2, c2))