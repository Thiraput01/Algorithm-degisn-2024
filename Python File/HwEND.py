population = [
    {'id': 71380410,
    'vaccinated': True,
    'coordinate': (142.35632697722804, 233.67679618203823)},
    {'id': 85109525,
    'vaccinated': False,
    'coordinate': (142.62075930591354, 214.76919336251675)},
    {'id': 57521675,
    'vaccinated': False,
    'coordinate': (143.65899867666593, 224.0267344699912)},
    {'id': 35373207,
    'vaccinated': False,
    'coordinate': (144.72263074267343, 217.75509778988294)},
    {'id': 96365445,
    'vaccinated': False,
    'coordinate': (146.76725209497084, 203.64110005292503)}
]
    
def get_coordinates(population, vaccinated):
    d = {}
    for i in population:
        if i['vaccinated'] == vaccinated:
            d[i['id']] = i['coordinate']
            
    return {d['id'] : i['coordinate'] for i in population }
            
def get_all_unjabbed_pairs(population, radius):
    unjabbed = list(get_coordinates(population,False).items())
    ans = []
    for i in range(len(unjabbed)):
        for j in range(i+1,len(unjabbed)):
            a = (unjabbed[i][1][0] - unjabbed[j][1][0]) **2
            b = (unjabbed[i][1][1] - unjabbed[j][1][1]) **2
            if (a+b)**0.5 <= radius:
                ans.append([unjabbed[i][0],unjabbed[j][0]])
    ans = sorted([(i,o) if o > i else (o,i) for i,o in ans])
    return ans

def first_hop(population, id, radius):
    all_hop = get_all_unjabbed_pairs(population, radius)
    ans = []
    for i in range(len(all_hop)):
        for j in range(len(all_hop[0])):
            if all_hop[i][j] == id:
                ans.append(all_hop[i])
    ans = sorted([o for i in ans for o in i if o != id])
    return ans

def get_adjacency_set(pairs):
    d = {}
    for id1,id2 in pairs:
        if id1 in d:
            d[id1].add(id2)
        else:
            d[id1] = {id2}
    for id2,id1 in pairs:
        if id1 in d:
            d[id1].add(id2)
        else:
            d[id1] = {id2}
    return d


def get_infectable_ids(pairs, seed):
    pair = get_adjacency_set(pairs)
    out = set()
    f = [seed]
    while f != []:
        p = f.pop(0)
        out.add(p)
        f += [i for i in pair[p] if i not in out]
    return out

def get_all_clusters(pairs):
    pair = get_adjacency_set(pairs)
    ans = []
    for i in pair:
        if get_infectable_ids(pairs, i) not in ans:
            ans.append(get_infectable_ids(pairs, i))
    return ans

pairs=[(1,2),(1,3),(2,4),(4,5),(7,8)]
print(get_all_clusters(pairs))