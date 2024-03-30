#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> G; // Adjacency list representation

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, v;
    cin >> n >> m >> k;
    cin >> v;

    vector<int> start(k);
    G.resize(n);

    for (int i = 0; i < k; ++i) cin >> start[i];

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[b].push_back({a, c});
    }

    // Dijkstra's Algorithm
    set< pair<int, int> > s; // {cost, u}
    vector<int> dist(n, 1e9);
    s.insert({0, v});

    while (!s.empty()) {
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        
        for (auto &p : G[u]) {
            int v = p.first;
            int w = p.second;
            if (w + c < dist[v]) {
                s.erase({dist[v], v});
                dist[v] = w + c;
                s.insert({dist[v], v});
            }
        }
    }

    int ans = 1e9;
    for (auto &s : start) {
        ans = min(ans, dist[s]);
    }
    cout << ans;
}
