n = int(input())
party = {}
read = []
for i in range(n):
    x = input().strip()
    party[x] = set()
    read.append(x)
m = int(input())
for i in range(m):
    x, p = input().strip().split()
    party[p].add(x)
f = int(input())
vote = {}
for i in range(f):
    x, v = input().strip().split()
    vote[x] = v
for i in read:
    temp = {'X':0,'Y':0,'N':0}
    for j in party[i]:
        if j in vote:
            temp[vote[j]] += 1
    m = max([o for o in temp.values()])
    cobra = []
    z = set()
    for j in party[i]:
        if j in vote:
            if temp[vote[j]] != m:
                cobra.append(j)
            else:
                z.add(vote[j])
    
    print(i)
    if cobra == [] and len(z) == 1:
        print('No cobra')
    elif len(z) != 1:
        print('Inconclusive')
    else:
        a = ' '.join(sorted(cobra))
        print(a)

    
    