import sys
import bisect

lines = sys.stdin.readlines()
input_index = 0

n, K, m = map(int, lines[input_index].split())
input_index += 1

pf = [0]
for _ in range(n):
    pf.append(pf[-1] + int(lines[input_index]) - m)
    input_index += 1

pf_minus_m = [pf[i] for i in range(1, n + 1)]

for _ in range(K):
    p, w = map(int, lines[input_index].split())
    input_index += 1
    print(bisect.bisect_left(pf_minus_m, w + pf[p-1]))
