import sys

def input():
    return sys.stdin.readline()

n = int(input())
l = [] 
for i in range(n):
    x, y = map(int, input().split())
    l.append([x, y])
    
l.sort()
max_y = l[-1][1]
c = 1
for i in l[::-1]:
    if i[1] > max_y:
        max_y = i[1]
        c += 1
print(c)