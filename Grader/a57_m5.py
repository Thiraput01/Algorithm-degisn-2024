import sys

def input():
    return sys.stdin.readline()
_ = int(input())
v = list(map(int, input().split()))

max_sum, min_sum = v[0], v[0]
cur_max, cur_min = 0, 0
total_sum = 0
for i in v:
    cur_max= max(cur_max + i, i)
    cur_min = min(cur_min + i, i)
    total_sum += i
    max_sum = max(cur_max, max_sum)
    min_sum = min(cur_min, min_sum)


print(max(max_sum, total_sum-min_sum) if max_sum > 0 else max_sum)
