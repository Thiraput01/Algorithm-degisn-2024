n, m = map(int, input().split())
v = [0] + list(map(int, input().split()))
w = [0] + list(map(int, input().split()))
dp = []
for i in range(n+1):
    dp.append(list(map(int, input().split())))

a = n
b = m

l = []
while a > 0 and b > 0:
    if b >= w[a] and dp[a-1][b-w[a]] + v[a] >= dp[a-1][b]:
        l.append(a)
        b -= w[a]z
        a -= 1
    else:
        a -= 1
print(len(l))
print(' '.join(map(str, l)))
    