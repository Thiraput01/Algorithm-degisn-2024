#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

void dfs(int node){
    for(auto &i: G[node]){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}


int main(){
    int v, e;
    cin >> v >> e;
    G.resize(v+1);
    visited.resize(v+1, false);
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // for(int i=1; i<=G.size(); ++i){
    //     cout << i << ": ";
    //     for(auto j : G[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    int cc_num = 0;
    for(int i=1; i<=v; ++i){
        if(!visited[i]){
            dfs(i);
            cc_num += 1;
        }
    }
    cout << cc_num;
}