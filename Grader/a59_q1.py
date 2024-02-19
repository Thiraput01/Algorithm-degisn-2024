def cal(n, l, c):
    global count
    if n == 0:
        return c
    #ex 1110
    a = int("1"*l) #1111
    b = int("1"*(l+1)) #11111
    tmp1 = abs(n-a) #1
    tmp2 = abs(n-b) #10001
    c += l
    if tmp1 <= tmp2:
        while tmp1 >= a:
            tmp1 -= a
            c += l
        
        way1 = cal(tmp1, len(str(tmp1)), c)
    else:
        c += 1
        while tmp2 >= a:
            tmp2 -= a
            c += l
            
        way2 =  cal(tmp2, len(str(tmp2)), c)
    
    check = way1 > way2
    return way1 if check else way2


n = int(input())
l = len(str(n))
count = 0
cal(n, l, 0)
print(count)