import sys

def input():
    return sys.stdin.readline()

def cal(time, v):
    s = len(v)
    for each_seat_time in v:
        s += time // each_seat_time
    return s
    
n, a = map(int, input().split())
v = [int(e) for e in input().split()]
v.sort()
ans = [int(e) for e in input().split()]
for customer in ans:
    left = 0
    right = sys.maxsize
    # D&C part used to calculate the time for customer 
    while(left < right):
        mid = (left+right)//2
        #cal the number of customers on the "mid" time
        if (cal(mid, v) >= customer):
            right = mid
        else:
            left = mid+1
    #if come out, means that found the time
    print(left)