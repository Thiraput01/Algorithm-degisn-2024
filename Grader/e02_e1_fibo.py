n = int(input())
f0 = 0
f1 = 1
tmp = 1 if n == f1 else 0
for i in range(2, n+1):
    tmp = f0 + f1
    f0 = f1
    f1 = tmp
print(tmp)