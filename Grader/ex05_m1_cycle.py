from collections import deque

def print_graph(G):
    for i in range(len(G)):
        print(i, ":", *G[i])

def check_bfs(G, start):
    visited = [False] * len(G)
    q = deque()
    q.append(start)
    visited[start] = True
    parent = [-1] * len(G)
    while q:
        n = q.popleft()
        for i in G[n]:
            if not visited[i]:
                visited[i] = True
                q.append(i)
                parent[i] = n
            elif parent[n] != i:
                return True
    return False

def main():
    T = int(input())
    for _ in range(T):
        n, e = map(int, input().split())
        G = [[] for _ in range(n)]
        for _ in range(e):
            a, b = map(int, input().split())
            G[a].append(b)
            G[b].append(a)
        is_cyc = False
        for i in range(n):
            if check_bfs(G, i):
                is_cyc = True
                break
        if is_cyc:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
