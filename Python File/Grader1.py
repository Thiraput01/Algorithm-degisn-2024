x = input().strip().split()
x.sort()
def letter_point(x):
    x1 = ['A','E','I','L','N','O','R','S','T','U']
    x2 = ['D','G']
    x3 = ['B','C','M','P']
    x4 = 'FHXWY'
    x5 = 'K'
    x8 = 'JX'
    x10 = 'QZ'
    score = 0
    for i in x:
        if i in x1:
            score += 1
        elif i in x2:
            score += 2
        elif i in x3:
            score += 3
        elif i in x4:
            score += 4
        elif i in x5:
            score += 5
        elif i in x8:
            score += 8
        elif i in x10:
            score += 10
    return score
aaa = []        
for i in x:
    l = letter_point(i)
    aaa.append([l,i])
aaa.sort(reverse = True)
p = []
for n,c in aaa:
    p.append([c,n])
    
for k in range(len(p)):
    pass
p = [[-1*(a[1]),a[0]] for a in p]
p.sort()
p = [[a[1],-1*(a[0])] for a in p]
for i,o in p:
    print(i,o)











#COMPUTER QUEEN QUITE QUIET ZEBRA
    
