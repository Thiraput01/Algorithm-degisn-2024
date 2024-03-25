nomimono = {'Cappuccino':{'S':60,'L':70}, 'Espresso':{'S':45,'L':50}, 'Latte':{'S':65,'L':75}}
d,s,n = input('Enter drink, size and number: ').strip().split()
raka = 0
if d not in nomimono:
    print('Drink not available')
else:
    for i in nomimono:
        if d == i and s in nomimono[i]:
            raka = nomimono[i][s] * int(n)
            print('Total :' + str(raka))
            break
        elif s not in nomimono[i]:
            print('Incorrect size')
            break

            