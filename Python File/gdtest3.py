n,m,k = input().strip().split()
n,m,k = int(n), int(m), int(k)
nam = []
fac = []
faculty = {}
for i in range(n):
    n,f = input().strip().split()
    if f not in faculty:
        faculty[f] = [n]
    else:
        faculty[f].append(n)
    nam.append(n)
    fac.append(f)
ometeto = {}
for i in range(m):
    x = input().strip().split()
    if x[0] not in ometeto:
        ometeto[x[0]] = x[1:]
    else:
        ometeto[x[0]] += x[1:]
for i in range(k):
    er = {}
    l = set()
    out = set()
    gogo = []
    x = input().strip().split()
    for j in range(len(x)):
        go = set()
        call = ometeto[x[j]]
        for f in call:
            if f in nam:
                o = nam.index(f)
                fa = fac[o]
                go.add(fa)
        gogo.append(go)
    out = []
    kuy = gogo[0]
    for m in gogo:
        kuy &= m
    if len(kuy) == 0:
        print('None')
    else:
        a = list(kuy)
        print(' '.join(sorted(a)))
        
               
        
        