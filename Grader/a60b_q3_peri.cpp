#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G; //undirected graph

int bfs(int start, int k){
    vector<int> dist(G.size(), -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;
    int ans = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &i : G[u]){
            if(dist[i] == -1){ 
                dist[i] = dist[u] + 1;      
                q.push(i);
            }

        }
    }
    for(auto &i : dist){
        if(i == k) ans++;
    }
    return ans;

}


int main(){
    int n, e, k;
    cin >> n >> e >> k;
    G.resize(n+1);
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = bfs(0, k);
    cout << ans;
}