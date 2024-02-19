def get_sum(s, from_idx, to_idx):
    return s[to_idx] - s[from_idx - 1]

def mss(v, l, r, s):
    if l == r:
        return v[l]
    mid = (l + r) // 2
    r1 = mss(v, l, mid, s)
    r2 = mss(v, mid + 1, r, s)
    mxl = get_sum(s, mid, mid)
    mxr = get_sum(s, mid + 1, mid + 1)
    #B[*][m]
    for i in range(l, mid + 1):
        mxl = max(mxl, get_sum(s, i, mid))
    #B[m+1][*]
    for i in range(mid + 2, r + 1):
        mxr = max(mxr, get_sum(s, mid + 1, i))
    r3 = mxl + mxr
    return max(r1, r2, r3)

n = int(input())
v = [0] * (n + 1)
s = [0] * (n + 1)

inputs = input().split()

for i in range(1, n + 1):
    v[i] = int(inputs[i - 1])

for i in range(1, n + 1):
    s[i] = s[i - 1] + v[i]

ans = mss(v, 1, n, s)
print(ans)
