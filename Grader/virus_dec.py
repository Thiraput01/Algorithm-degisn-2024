def check(l):
    if(len(l) == 2):
        return a==[0,1]
    m = len(l)//2
    tmp = l[:m]
    return (check(tmp) or check(tmp[::-1])) and check(l[m:])

n, k = [int(e) for e in input().split()]
for _ in range(n):
    a = [int(e) for e in input().split()]
    print("yes" if check(a) else "no")