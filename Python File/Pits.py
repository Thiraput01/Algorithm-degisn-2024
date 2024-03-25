num = int(input())
k = []
pits = []
for zzz in range(num):
    o = int(input())
    k.append(o)
for i in range(1,len(k)+1):
    if k[i%(len(k))] < k[(i+1)%(len(k))] and k[i%(len(k))] < k[(i-1)%(len(k))]:
        if i == num:
            i = 0
        pits.append(i)
if pits == [] :
    print('No pits')
else:
    for e in pits:
        print(e)
        
#[1,2,3,4]