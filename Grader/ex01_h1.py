import sys

n = int(input())
for i in range(n):
    num = int(input())
    #find n that close to n(n+1) = num
    l = 1
    r = int(num**(1/2) + 1)
    while l<r:
        mid = (l+r)//2
        sum_mid = (mid*(mid+1))//2
        if sum_mid >= num:
            r = mid
        else:
            l = mid+1
    print(l)