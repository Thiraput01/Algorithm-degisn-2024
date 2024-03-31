#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;

    vector< vector< pair<int, int> > > G(n);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    //prims algo
    vector<int> cost(n, INF);
    set<pair<int, int>> s; //{cost, node}
    vector<bool> used(n, 0);

    cost[0] = 0;
    s.insert({0, 0});

    while(!s.empty()){
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        used[u] = 1;
        for(auto &p : G[u]){
            int v = p.first;
            int w = p.second;
            if(w < cost[v] && !used[v]){
                s.erase( {cost[v], v} );
                cost[v] = w;
                s.insert( {cost[v], v} );
            }
        }
    }
    sort(cost.begin()+1, cost.end(), greater<int>());
    while(q--){
        int d;
        cin >> d;
        cout << cost[d] << '\n';
    }
}