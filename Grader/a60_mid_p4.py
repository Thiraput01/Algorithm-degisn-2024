def merge(v, l, r, k):
    global a
    if(k[0]<=0 or l==r-1):
        return
    mid = (l+r) //2
    if(k[0]>0):
        v[mid], v[mid-1] = v[mid-1], v[mid]
    k[0] -= 2
    merge(v, l, mid, k)
    merge(v, mid, r, k)
    
    
n, k = map(int, input().split())
a = [0] * n
for i in range(1, n+1):
    a[i-1] = i
k = [k-1]
merge(a, 0, n-1, k)
print(-1 if k[0]!=0 else ' '.join(map(str, a)))