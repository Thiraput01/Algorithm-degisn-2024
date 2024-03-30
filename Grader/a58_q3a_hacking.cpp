#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> G(n);//adjacent list
    vector<int> att(k);
    vector<int> w(n);

    for(int i=0; i<k; ++i) cin >> att[i];

    for(int i=0; i<n; ++i) cin >> w[i];
    
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> cost(n, INT_MAX);
    queue<int> q;
    for(auto &a : att){
        cost[a] = w[a];
        q.push(a);
    }

    while(!q.empty()){ 
        int u = q.front(); q.pop();
        for(auto &v : G[u]){
            if(cost[u]+w[v] < cost[v]){
                cost[v] = cost[u] + w[v];
                q.push(v);
            }
        }
    }
    int ans = -1;
    for(auto &c : cost) ans = max(ans, c);
    cout << ans;
}