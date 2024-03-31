#include <bits/stdc++.h>

using namespace std;

vector<int> adj(vector<vector<int>> &w, int u){
    vector<int> res;
    for(int v=0; v<w.size(); ++v){
        if(w[u][v]!=-1 && u!=v) res.push_back(v);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n, 0)); //adjacent matrix
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> w[i][j];
        }
    }
    //dijkstra
    set< pair<int, int> > s;
    vector<int> cost(n, 1e9);
    cost[0] = 0;
    s.insert( {0, 0} );
    while(!s.empty()){
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto &v : adj(w, u)){
            if(c + w[u][v] < cost[v]){
                s.erase( make_pair(cost[v], v) );
                cost[v] = c + w[u][v];
                s.insert( make_pair(cost[v], v) );
            }
        }
    }
    int ans = -1;
    for(auto &c : cost) ans = max(ans, c);
    int res = (ans!=1e9)? ans: -1;
    cout << res;
}