file = input().strip()
s1 = input()
s2 = input()
fn = open(file,'r')

def replace(line,st1,st2):
    st1 = st1.lower()
    line = '/' + line
    start = 0
    first = line.find('/',start)
    current = ''
    while True:
        last = line.find('/',first+1)
        if last == -1:
            break
        current += line[first+1:last]
        l_cur = len(current)
        same_char = True
        if len(st1) == l_cur:
            for i in range(l_cur):
                if st1[i] != '?':
                    if st1[i].lower() != current[i].lower():
                        same_char = False
            if same_char:
                line = line[:first+1] + st2 + line[last:]
        elif l_cur == 0:
            last += 1
        start = last-1
        first = line.find('/',start)
        current = ''
    return line
                    
                    
ans = ''
            
for l in fn:
    ans += replace(l,s1,s2)[1:]

print(ans)
    
    