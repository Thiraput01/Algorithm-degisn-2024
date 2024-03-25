#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

int bfs(int node, int k){
    queue<int> q;
    vector<int> dist(G.size(), -1);

    q.push(node);
    dist[node] = 0;
    int friends = 1; //oneself is 1

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] == k) continue;
        
        for(auto &i : G[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                friends++;
                q.push(i);
            }
        }

    }
    return friends;
}
int main(){
    int n, e, k;
    cin >> n >> e >> k;
    G.resize(n);
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = -1;
    for(int i=0; i<n; ++i){
        ans = max(ans, bfs(i, k));
    }
    cout << ans;
}