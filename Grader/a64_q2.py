import sys

def input():
    return sys.stdin.readline()

n = int(input())
v = list(map(int, input().split()))

#first round
cur_sum1 = 0
mss1 = -sys.maxsize
l, r = 0, 0
tmp_l = 0
for i in range(n):
    cur_sum1 += v[i]
    if(cur_sum1 >= mss1):
        mss1 = cur_sum1
        r = i
        l = tmp_l
    if(cur_sum1 < 0):
        cur_sum1 = 0
        tmp_l = i+1
#second round --> if i between [l,r] skip
cur_sum2 = 0
mss2 = -sys.maxsize
for i in range(n):
    if l <= i <= r:
        continue
    cur_sum2 += v[i]
    mss2 = max(mss2, cur_sum2)
    cur_sum2 = max(cur_sum2, 0)
    
    
mss2 = 0 if mss2<0 else mss2
print(mss1+mss2)