def check(l):
    if(len(l) == 4):   
        condition = abs(sum(l[:2]) - sum(l[2:])) <= 1
        return condition
    m = len(l) // 2
    con2 = abs(sum(l[:m]) - sum(l[m:])) <= 1
    return check(l[:m]) and check(l[m:]) and con2

n, k = [int(e) for e in input().split()]
for _ in range(n):
    a = [int(e) for e in input().split()]
    print("yes" if check(a) else "no")
    