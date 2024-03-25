from collections import deque

def bfs(sr, sc, fr, fc):
    q = deque()
    dist = [[0 for _ in range(fc+1)] for _ in range(fr+1)]
    visited = set()
    visited.add((0, 0))
    q.append([sr,sc])
    while q:
        curr, curc = q.popleft()
        l = [curr, curc-1]
        r = [curr, curc+1]
        t = [curr-1, curc]
        b = [curr+1, curc]
        for x, y in [l, r, t, b]:
            if (0 <= x <= fr and 0 <= y <= fc) and (maze[x][y] == ".") and (x, y) not in visited:
                visited.add((x, y))
                q.append([x, y])
                dist[x][y] = dist[curr][curc] + 1
    return dist[fr][fc] if dist[fr][fc] != 0 else -1


row, col = map(int, input().split())
maze = []
for _ in range(row):
    maze.append(input().strip())

print(bfs(0, 0, row-1, col-1))