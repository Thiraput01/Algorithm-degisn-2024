# input = 1 2 3 3 3 3 4 5 6
# output = [2:6]
d = [int(e) for e in input().split()] + [23523454235]
first_char = 0
last_char = 0
max_count = 0
count = 1
for i in range(len(d)-1):
    if d[i] == d[i+1]:
        count += 1
    else:
        if max_count < count:
            max_count = count
            last_char = i + 1
            first_char = (i - count) + 1
        count = 1
print(first_char)
print(last_char)
            
            
    
    
