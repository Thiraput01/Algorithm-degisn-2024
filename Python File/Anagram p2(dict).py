inp1 = input().strip()
inp2 = input().strip()
inp11 = inp1.upper()
inp22 = inp2.upper()
l1 = []
l2 = []
for q in inp11:
    if q in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        l1.append(q)
for r in inp22:
    if r in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        l2.append(r)
l1.sort()
l2.sort()
d1 = {}
d2 = {}

for k in l1:
    if k in d1:
        d1[k] += 1
    else:
        d1[k] = 1
for m in l2:
    if m in d2:
        d2[m] += 1
    else:
        d2[m] = 1
        
key = []

for i in d1:
    if i in d2:
        if d1[i] > d2[i]:
            key.append([d2[i],i])
        elif d1[i] < d2[i]:
            key.append([d1[i],i])
        else:
            key.append([d1[i],i])
#ได้แล้วว่า Anagram จะเป็นข้อความอะไร
l111 = []
l222 = []
for e,m in d1.items():
    l111.append([m,e])
for ee,mm in d2.items():
    l222.append([mm,ee])
for num,char in key:
    pass

l3 = [o[1] for o in l111]
l4 = [o[1] for o in l222]
key_l = [o[1] for o in key]


not_st1 = []
not_st2 = []

l1 = []
l2 = []

for ii in l111:
    if ii[1] not in key_l:
        not_st1.append(ii)
    else:
        l1.append(ii)
        
for iii in l222:
    if iii[1] not in key_l:
        not_st2.append(iii)
    else:
        l2.append(iii)
#ตัดให้len เท่ากัน แล้วยัดตัวที่เลยลงในลิสต์
if key == []:
    for uwu in l1:
        not_st1.append(uwu)
    for tot in l2:
        not_st2.append(tot)
else:
    for n in range(len(l1)):
        if l1[n][0] > key[n][0]:
            dif = l1[n][0] - key[n][0]
            not_st1.append([dif,l1[n][1]])

    for nn in range(len(l2)):
        if l2[nn][0] > key[nn][0]:
            dif = l2[nn][0] - key[nn][0]
            not_st2.append([dif,l2[nn][1]])
ans_st1 = []
ans_st2 = []
for uuu,www in not_st1:
    ans_st1.append([www,uuu])
for yy,zz in not_st2:
    ans_st2.append([zz,yy])
ans_st1.sort()
ans_st2.sort()
def printans(s1,s2):
    ans1 = ''
    ans2 = ''
    c1 = 1
    c2 = 1
    if s1 == []:
        ans1 += ' - None'
    else:
        for i in s1:
            i[0] = i[0].lower()
            if c1 == len(s1):
                if i[1] > 1:
                    ans1 += " - remove {} {}'s".format(i[1],i[0])
                else:
                    ans1 += " - remove {} {}".format(i[1],i[0])
                 
            else:
                if i[1] > 1:
                    ans1 += " - remove {} {}'s".format(i[1],i[0]) + '\n'
                else:
                    ans1 += ' - remove {} {}'.format(i[1],i[0]) + '\n'
            c1 += 1
    if s2 == []:
        ans2 += ' - None'
    else:
        for e in s2:
            e[0] = e[0].lower()
            if c2 == len(s2):
                if e[1] > 1:
                     ans2 += " - remove {} {}'s".format(e[1],e[0])
                else:
                    ans2 += " - remove {} {}".format(e[1],e[0])
            else:
                if e[1] > 1:
                    ans2 += " - remove {} {}'s".format(e[1],e[0]) + '\n'
                else:
                    ans2 += ' - remove {} {}'.format(e[1],e[0]) + '\n'
            c2 += 1
    return ans1, ans2

a1, a2 = printans(ans_st1,ans_st2)
print(inp1)
print(a1)
print(inp2)
print(a2)