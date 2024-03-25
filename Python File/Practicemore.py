n = int(input())
item = {}
c = []
# {p1:[[b3,11],[b1,11]], p2:[[b1,10],[b2,9]]}
for i in range(n):
    x = input().strip().split()
    if x[0] == 'B':
        x[3] = int(x[3])
        if x[2] not in item:
            item[x[2]] = [[x[1],x[3]]]
        else:
            for k in item[x[2]]:
                if k[0] == x[1]:
                    idx = item[x[2]].index(k)
                    item[x[2]].pop(idx)
            item[x[2]].append([x[1],x[3]])
    elif x[0] == 'W':
        if x[2] in item:
            for k in item[x[2]]:
                if k[0] == x[1]:
                    idx = item[x[2]].index(k)
                    item[x[2]].pop(idx)
    if x[1] not in c:
        c.append(x[1]) 
#{'p1': [['b3', 11], ['b1', 11]],
#'p2':[['b2', 9]], 'p4': [['b2', 1], ['b3', 5]]}
for i in item:
    if item[i] != []:
        m = max([o[1] for o in item[i]]) 
        win = [[o[0],o[1]] for o in item[i] if o[1] == m]
        winner = win[0]
        item[i] = winner
item = {k:v for k,v in item.items() if v != []}
result = {}
for i in item:
    if item[i][0] not in result:
        result[item[i][0]] = [[i,item[i][1]]]
    else:
        result[item[i][0]].append([i,item[i][1]])
    result[item[i][0]].sort()
c.sort()
for i in c:
    if i not in result:
        print(i + ': $0')
    else:
        l = result[i]
        money = 0
        person = []
        for p,m in l:
            money += m
            person.append(p)
        person = ' '.join(sorted(person))
        print('{}: ${} -> {}'.format(i,money,person))
            
            
'''{'b3': [['p1', 11], ['p4', 5]], 'b2': [['p2', 9]]}
['b3', 'b1', 'b2']'''
