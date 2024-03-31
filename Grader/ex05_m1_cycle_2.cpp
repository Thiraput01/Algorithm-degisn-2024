#include <bits/stdc++.h>
using namespace std;
bool is_cycle(vector<vector<int>> &G, vector<bool> &visited, int u, int prev){
    visited[u] = 1;
    for(auto &v : G[u]){
        if(!visited[v]){
            if(is_cycle(G, visited, v, u)) return true;
        }
        else if(v != prev) return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        vector<vector<int>> G(n); //adjacent list
        for(int i=0; i<e; ++i){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<bool> visited(n, 0);
        bool ok = true;
        for(int i=0; i<n; ++i){
            if(!visited[i] && is_cycle(G, visited, i, -1)){
                ok = false;
                break;
            }
        }
        if(!ok) cout << "YES\n";
        else cout << "NO\n";
    }
}