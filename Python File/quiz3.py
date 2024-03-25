n,m,k = input().strip().split()
n,m,k = int(n), int(m), int(k)
faculty = {}
for i in range(n):
    n,f = input().strip().split()
    if f not in faculty:
        faculty[f] = [n]
    else:
        faculty[f].append(n)
ometeto = {}
for i in range(m):
    x = input().strip().split()
    if x[0] not in ometeto:
        ometeto[x[0]] = x[1:]
    else:
        ometeto[x[0]] += x[1:]
for i in range(k):
    x = input().strip().split()
    p = set()
    q = set()
    for j in range(len(x)):
        for o in ometeto[x[j]]:
            for u in faculty:
                for uu in faculty[u]:
                    if uu == o:
                        if j == 0:
                            p.add(u)
                        else:                            
                            q.add(u)
    print(p)
    print(q)
    z = p & q
    z = sorted(list(z))
    print(' '.join(z))