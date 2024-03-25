# input = 1+2+3+5  output = 11
# input = +4+2-3   output = 3
# input = -2+4+6   output = 8

num = sum([int(a) for a in input("Enter number: ").replace("+"," ").replace("-"," -").split()])
print(num)