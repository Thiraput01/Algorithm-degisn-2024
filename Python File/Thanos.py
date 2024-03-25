def perform(v, l, r, A, B):
    if r == l:
        if v[r] != 0:
            return B * v[r] * 1
        else:
            return A
    mid = (l + r) // 2
    x = perform(v[l:mid+1], l, mid, A, B)
    y = perform(v[mid+1:r+1], mid + 1, r, A, B)
    way_1 = x + y
    avenger_number = sum(v[l:r+1])
    way_2 = B * avenger_number * (r - l + 1) if avenger_number!=0 else A
    return min(way_1, way_2)

p, k, A, B = map(int, input().split())
arr_len = 2 ** p
avenger = [0] * (arr_len + 1)
num = [int(e) for e in input().split()]
for i in num:
    avenger[i] += 1
print(perform(avenger, 1, arr_len, A, B))
