import ast

input_str = input("nums = ")
Numlist = ast.literal_eval(input_str)
target = int(input("Target = "))
out = []
for i in range(0,len(Numlist)):
    for j in range(i+1,len(Numlist)):
        if Numlist[i] + Numlist[j] == target:
            out.append(i)
            out.append(j)
print(out)
            
        
    
