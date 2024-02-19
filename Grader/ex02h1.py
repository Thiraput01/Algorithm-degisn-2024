import sys

INF = 10**9 + 7

def get_distance(a, b):
    diffX = a[0] - b[0]
    diffY = a[1] - b[1]
    return diffX * diffX + diffY * diffY

def solve(sortedX, sortedY):
    N = len(sortedX)
    if N == 1:
        return INF
    if N == 2:
        return get_distance(sortedX[0], sortedX[1])

    mid = (N - 1) // 2
    XL = sortedX[:mid + 1]
    XR = sortedX[mid + 1:]
    YL = []
    YR = []
    for x, y in sortedY:
        if x <= XL[-1][0]:
            YL.append((x, y))
        else:
            YR.append((x, y))

    minDist = min(solve(XL, YL), solve(XR, YR))
    strip = [(x, y) for x, y in sortedY if (x - XL[-1][0]) * (x - XL[-1][0]) < minDist]

    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if (strip[j][1] - strip[i][1]) * (strip[j][1] - strip[i][1]) >= minDist:
                break
            minDist = min(minDist, get_distance(strip[i], strip[j]))

    return minDist

# Input processing
N = int(input().strip())
sortedX = []
sortedY = []
for _ in range(N):
    x, y = map(int, input().split())
    sortedX.append((x, y))
    sortedY.append((y, x))

sortedX.sort()
sortedY.sort()
sortedY = [(y, x) for x, y in sortedY]

# Calling the solve function
print(solve(sortedX, sortedY))


