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
    priority_queue< pair<int, int> ,
                    vector< pair<int, int> >,
                    greater< pair<int, int> > > pq; // {cost, u}
    vector<int> dist(n, 1e9);
    pq.push( {0, v} );

    while (!pq.empty()) {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        for (auto &p : G[u]) {
            int v = p.first;
            int w = p.second;
            if (w + c < dist[v]) {
                dist[v] = w + c;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 1e9;
    for (auto &s : start) {
        ans = min(ans, dist[s]);
    }
    cout << ans;

    return 0;
}
