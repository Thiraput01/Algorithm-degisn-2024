n = int(input())
country = {}
prathed = []
for i in range(n):
    t,c = input().strip().split()
    if c not in country:
        country[c] = {t}
    else:
        country[c].add(t)
x = input().strip().split()
while x[0] != 'q':
    t = {}
    o = []
    for i in country:
        for j in country[i]:
            if j in x:
                if i not in t:
                    t[i] = [j]
                else:
                    t[i].append(j)
    ok = True
    allteams = []
    for o in country.values():
        for i in o:
            allteams.append(i)
    for i in t:
        if len(t[i]) != 1:
            ok = False
    for i in x:
            if i not in allteams:
                ok = False
                
       
    if ok:
        print('OK')
    else:
        print('Not OK')
    x = input().strip().split()
    
        

