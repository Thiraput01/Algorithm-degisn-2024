x = int(input())
l = []
for i in range(x):
    y = int(input())
    l.append(y)
k = []
#[1,2,3,4]
for i in range(len(l)):#len = 2 ==> 0,1,2,3
    if l[i] > l[(i+1)%len(l)] and l[(i+1)%len(l)] < l[(i+2)%len(l)]:
        if i == len(l)-1:
            i = 0
        k.append(i)
print(k)