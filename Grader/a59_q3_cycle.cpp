#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dist, parent;
int ans;

void dfs(int node, int prev){
    //cout << "now recur at node: "<<node<<", ";
    for(auto &i : G[node]){
        //cout << "adj node is: " << i << ", ";
        if(dist[i] == -1){
            dist[i] = dist[node] + 1;
            dfs(i, node);
        }else if(i != prev){
            //cout << "current adj node: "<< i << "\n";
            //cycle detected i=0, prev=5, node=2s
            //ans = dist[2] - dist[5] + 1
            //    = 4 - 0 + 1
            //cout << "node: "<<node<<" dist[node]= "<<dist[node]<<", i: "<<i<<" dist[i]= "<<dist[i] << "\n";
            ans = abs(dist[node] - dist[i]) + 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    G.resize(n+1);
    dist.resize(n, -1);
    parent.resize(n);
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dist[0] = 0;
    dfs(0, -1);
    cout << ans;
}