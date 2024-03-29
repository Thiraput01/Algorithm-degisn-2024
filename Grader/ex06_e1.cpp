#include <bits/stdc++.h>

using namespace std;

vector<int> adj(vector<vector<int>> &w, int u){
    vector<int> res;
    for(int v=0; v<w.size(); ++v){
        if(w[u][v]!=-1) res.push_back(v);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n, -1));
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            int num;
            cin >> num;
            w[i][j] = w[j][i] = num;
        }
    }

    vector<int> cost(n, INT_MAX);
    vector<bool> taken(n, 0);

    set<pair<int, int>> s; // {cost, node}
    s.insert( {0, 0} );
    while(!s.empty()){
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        taken[u] = true;
        for(auto &v : adj(w, u)){
            if(cost[v] > w[u][v] && !taken[v]){
                s.erase(make_pair(cost[v], v));
                cost[v] = w[u][v];
                s.insert(make_pair(cost[v], v));
            }
        }

    }
    int ans = 0;
    for(int i=1; i<n; ++i) ans += cost[i];
    cout << ans;
}