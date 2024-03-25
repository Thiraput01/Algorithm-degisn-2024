from sys import stdin as kb

def dq(p, a):
    if p == 0:
        return A if len(a) == 0 else B*len(a)
    if len(a) == 0:
        return A
    m = 2**(p-1)
    for i in range(len(a)+1):
        if i ==len(a) or m < a[i]:
            break
    al, ar = a[:i], [x-m for x in a[i:]]
    # print(a, m)
    # print(al, ar)
    return min(dq(p-1, al) + dq(p-1, ar), \
               A if len(a) == 0 else B*len(a)*(2**p))

p, _, A, B = map(int, kb.readline().split())
a = sorted(map(int, kb.readline().split()))
print(dq(p, a))
