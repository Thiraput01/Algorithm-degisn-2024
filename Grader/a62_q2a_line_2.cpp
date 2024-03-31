#include <bits/stdc++.h>

using namespace std;

bool is_cycle(vector<vector<int>> &G, vector<bool> &visited, int u, int prev){
    visited[u] = 1;
    if(G[u].size()>2) return true;
    for(auto &v : G[u]){
        if(!visited[v]){
            return is_cycle(G, visited, v, u);
        }else if(v != prev) return true;
    }
    return false;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> G(v); //adjacent list
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(v, 0);
    int cc = 0;
    for(int i=0; i<v; ++i){
        if(!visited[i]){
            if(!is_cycle(G, visited, i, i)) cc++;
        }
    }
    cout << cc;
}
