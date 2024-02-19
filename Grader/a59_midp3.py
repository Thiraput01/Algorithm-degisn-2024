def แปป(a, b):
    if len(a) == 1:
       return a == b
    mid = len(a)//2
    a1 = a[:mid]
    b1 = b[:mid]
    a2 = a[mid:]
    b2 = b[mid:]

    return (แปป(a1, b1) and แปป(a2, b2)) or (แปป(a1, b2)  and แปป(a2, b1))
    
    
เข้า = input().strip()
เช็ค = input().strip()
ถูกปะ = แปป(เข้า, เช็ค)
print( 'YES' if ถูกปะ else 'NO')


