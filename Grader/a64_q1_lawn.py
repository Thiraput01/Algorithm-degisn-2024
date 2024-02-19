def pfs(v):
    lv = len(v)
    tmp = [0]
    s = 0
    for i in v:
        s += i
        tmp.append(s)
    return tmp

def cal(v, a, b):
    pass


print(pfs([2, 3, 4, 5]))
# n, m, k = map(int, input().split())
# v = list(map(int, input().split()))
# for i in range(m):
#     a, b = map(int, input().split())
#     cal(v, a, b)