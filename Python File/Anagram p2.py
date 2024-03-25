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
d1 = []
d2 = []
have1 = []
have2 = []


for char1 in l1:
    if char1 not in have1:
        have1.append(char1)
for char2 in l2:
    if char2 not in have2:
        have2.append(char2)
for kk1 in have1:
    p = l1.count(kk1)
    d1.append([p,kk1])
for kk2 in have2:
    pp = l2.count(kk2)
    d2.append([pp,kk2])
    
        


d_1 = [o[1] for o in d1]
d_2 = [o[1] for o in d2]

#AAAAABBBAAA

        
key = []
print(d_1)
print(d_2)
for i in range(len(d_1)):
    if d_1[i] in d_2:
        if d1[i][1] == d2[i][1]:
            if d1[i][0] > d2[i][0]:
                key.append([d2[i][0],d_1[i]])
            elif d1[i][0] < d2[i][0]:
                key.append([d1[i][0],d_1[i]])
            else:
                key.append([d1[i][0],d_1[i]])

#ได้แล้วว่า Anagram จะเป็นข้อความอะไร


key_l = [o[1] for o in key]


not_st1 = []
not_st2 = []

l_1 = []
l_2 = []

for ii in d1:
    if ii[1] not in key_l:
        not_st1.append(ii)
    else:
        l_1.append(ii)
        
for iii in d2:
    if iii[1] not in key_l:
        not_st2.append(iii)
    else:
        l_2.append(iii)
#ตัดให้len เท่ากัน แล้วยัดตัวที่เลยลงในลิสต์

if key == []:
    for uwu in l_1:
        not_st1.append(uwu)
    for tot in l_2:
        not_st2.append(tot)
else:
    for n in range(len(l_1)):
        if l_1[n][0] > key[n][0]:
            dif = l_1[n][0] - key[n][0]
            not_st1.append([dif,l_1[n][1]])

    for nn in range(len(l_2)):
        if l_2[nn][0] > key[nn][0]:
            dif = l_2[nn][0] - key[nn][0]
            not_st2.append([dif,l_2[nn][1]])
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


    
    