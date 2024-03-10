import bisect
def solve(matrix, target):
    n = len(matrix)
    m = len(matrix[0])
    def findrow():
        l = []
        for i in matrix:
            l.append(i[0])
        pos = max(0, bisect.bisect_right(l, target) - 1)
        return pos
    tmp = matrix[findrow()]
    idx = bisect.bisect_left(tmp, target)
    if idx != len(tmp) and tmp[idx] == target:
        return True
    return False
    
        
        
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]; target = 3
# matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]; target = 13
# matrix = [[1],[3]]
# target = 3
print(solve(matrix, target))


