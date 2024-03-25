fn = open('data.txt','r')
st = ''
def delete(st):
    first = st.find('<')
    last = st.find('>',first+1)
    if first == -1 or last == -1:
        return st
    else:
        st = st[:first] + st[last+1:]
    return st
def upper(st):
    first = st.find('|')
    last = st.find('|',first+1)
    if first == -1 or last == -1:
        return st
    else:
        between = st[first+1:last]
        between = between.upper()
        st = st[:first] + between + st[last+1:]
        return st
for line in fn:
    p = line.strip()
    o = upper(p)
    q = delete(o)
    print(q)
    
