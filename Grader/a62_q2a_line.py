def dfs(node, parent):
    visited.add(node)
    n = len(G[node])
    if n > 2:
        return False
    for i in G[node]:
        if i not in visited:
            return dfs(i, node)
        elif parent != i:
            #its a cycle --> instant false
            return False

    return True
def find_line():
    line_num = 0
    for i in range(0, len(G)):
        if i not in visited:
            if(dfs(i, i)):
                line_num += 1
    return line_num


v, e = map(int, input().split())
G = {j: [] for j in range(v)}
for _ in range(e):
    a, b = map(int, input().split())
    G[a] += [b]
    G[b] += [a]
visited = set()
print(find_line())		

