# def gen(t, b, top, bottom, left, right):
#     global mt
#     if t == 0:
#         mt[top][left] = b
#         return
#     midc = (left+right)//2
#     midr = (top+bottom)//2
#     #gen top left
#     gen(t-1, b, top, midr, left, midc)
#     #gen top right
#     gen(t-1, b-1, top, midr, midc+1, right)
#     #gen bottom left
#     gen(t-1, b+1, midr+1, bottom, left, midc)
#     #gen bottom right
#     gen(t-1, b, midr+1, bottom, midc+1, right)

def gen(t, b, top, bottom, left, right):
    global mt
    if t == 0:
        mt[top][left] = b
        return
    midc = (left+right)//2
    midr = (top+bottom)//2
    #gen top left
    gen(t-1, b, top, midr, left, midc)
    #gen top right
    gen(t-1, b-1, top, midr, midr+1, right)
    #gen bottom left
    gen(t-1, b+1, midr+1, bottom, left, midc)
    #gen bottom right
    gen(t-1, b, midr+1, bottom, midc+1, right)

t, b = map(int, input().split())
if(t==b==0):
    print(0)
    quit()
a = 2**t
tmp = [0]*a
mt = [list(tmp) for _ in range(a)]
gen(t, b, 0, a-1, 0, a-1)
for i in mt:
    print(' '.join(map(str, i)))