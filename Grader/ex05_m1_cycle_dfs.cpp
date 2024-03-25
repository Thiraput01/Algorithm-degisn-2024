#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<vector<int>> &G, vector<int> &parent, vector<bool> &visited){
    visited[node] = 1;
    for(auto &i : G[node]){
        if(!visited[i]){
            parent[i] = node;
            if(dfs(i, G, parent, visited)) return true;
        }else if(i != parent[node]){
            return true;
        }
    }
    return false;
}
bool cycle_dfs(vector<vector<int>> &G){
    vector<bool> visited(G.size(), 0);
    vector<int> parent(G.size(), -1);
    for(int node=0; node<G.size(); ++node){
        if(!visited[node]){
            if(dfs(node, G, parent, visited)) return true;
        }
    }
    return false;
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, e;
        cin >> n >> e;
        vector<vector<int>> G(n);
        while (e--){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(cycle_dfs(G)) cout << "YES\n";
        else cout << "NO\n";

    }
}


