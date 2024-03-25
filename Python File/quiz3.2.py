def isenemy(m,n,l):
    for i in l:
        if m in i[0] and n in i[1]:
            return True
        elif m in i[1] and n in i[0]:
            return True
    else:
        return False
    
def table(x):
    allc = x[1:]
    ok = False
    allc = [allc[-1]] + allc
    for i in range(len(allc)-1):
        f = allc[i]
        s = allc[i+1]
        if isenemy(f,s,vs):
            return 'No'
        else:
            ok = True
    if ok:
        return 'Okay'
    else:
        return 'No'

x = input().split()
l = []
d = {}
vs = []
while x[0] != 'End':
    if x[0] == 'Ally':
        c = x[1:]
        for i in range(len(c)):
            for j in range(len(c)):
                if c[j] not in d:
                    d[c[j]] = {c[i]}
                else:
                    d[c[j]].add(c[i])
                if c[j] not in d:
                    d[c[j]] = c[i]
                else:
                    d[c[j]].add(c[i])
        l.append(c)
    elif x[0] == 'Enemy':
        c1, c2 = [x[1], x[2]]
        if c1 in d and c2 in d:
            enemy1 = list(d[c1])
            enemy2 = list(d[c2])
            vs.append([enemy1,enemy2])
        elif c1 in d:
            enemy1 = list(d[c1])
            vs.append([enemy1,[c2]])
        elif c2 in d:
            enemy2 = list(d[c2])
            vs.append([[c1],enemy2])
        else:
            vs.append([[c1],[c2]])
        
    elif x[0] == 'Table':
        print(table(x))
            
    x = input().split()
