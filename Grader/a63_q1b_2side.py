memo = {}

def solve(i, case):
    if i >= len(l):
        return 0
    if (i, case) in memo:
        return memo[(i, case)]
    if case == 1:
        a = l[i] + solve(i + w + 1, 2) # go use right
        c = solve(i + 1, 1) # not use
        memo[(i, 1)] = max(a, c)
        return memo[(i, 1)]
    if case == 2:
        b = r[i] + solve(i + w + 1, 1) # go use left
        c = solve(i + 1, 2) # not use
        memo[(i, 2)] = max(b, c)
        return memo[(i, 2)]



x = lambda: [*map(int, input().split())]
n, w, k = x()
l = x()
r = x()
case = 0
#case 1, use left
#case 2, use right
print(max(solve(0, 1), solve(0, 2)))