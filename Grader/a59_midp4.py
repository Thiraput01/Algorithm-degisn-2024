import sys
from collections import deque
def mcs(arr, k):
    if(max(arr) < 0):
        return max(arr)
    temp = [0]
    for i in range(len(arr)):
        temp.append(temp[i]+arr[i])
    dq = deque()
    mcs = -100000
    for i in range(len(temp)):
        if(len(dq) > 0 and i-dq[0] > k):
            dq.popleft()
        while(len(dq) > 0 and temp[dq[-1]] > temp[i]):
            dq.pop()
        dq.append(i)
        mcs = max(mcs, temp[i]-temp[dq[0]])
    return mcs

kb = sys.stdin
n, k = [int(i) for i in kb.readline().split()]
arr = [int(i) for i in kb.readline().split()]

print(mcs(arr, k))
