#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G; //directed graph

vector<int> bfs(int startnode){
    vector<int> dist(G.size(), -1); //need to return this
    queue<int> q;
    
    q.push(startnode);
    dist[startnode] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &i : G[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}

int main(){
    int n, m, t1, t2, t3;
    cin >> n;
    cin >> t1 >> t2 >> t3;
    G.resize(n+1);
    for(int i=1; i<=n; ++i){
        cin >> m;
        while(m--){
            int num;
            cin >> num;
            G[i].push_back(num);
        }
    }

    vector<int> d1 = bfs(t1);
    vector<int> d2 = bfs(t2);
    vector<int> d3 = bfs(t3);

    // cout << "dist1 :\n";
    // for(int i=1; i<=n; ++i) cout << d1[i] << " ";
    // cout << "\ndist2 :\n";
    // for(int i=1; i<=n; ++i) cout << d2[i] << " ";
    // cout << "\ndist3 :\n";
    // for(int i=1; i<=n; ++i) cout << d3[i] << " ";
    
    int ans = INT_MAX;
    for(int i=1; i<=n; ++i){
        if(d1[i]!=-1 && d2[i]!=-1 && d3[i]!=-1){
            int cur_max = max({d1[i], d2[i], d3[i]});
            ans = min(cur_max, ans);

        }
    }
    cout << ans;
    
}