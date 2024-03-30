#include <bits/stdc++.h>

using namespace std;

vector<int> adj(vector<vector<int>> &w, int u){
    vector<int> res;
    cout << "adj of " << u << " is : ";
    for(int i=0; i<w.size(); ++i){
        if(w[u][i]!=-1){
            res.push_back(i);
            cout << i << " ";
        }
    }
    cout << "\n";

    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> w(n, vector<int>(n, -1));
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }

    //prims algo
    vector<int> cost(n, INT_MAX);
    vector<bool> used(n, 0);
    set< pair<int, int> > s; // {cost, node}

    s.insert( {0, 0} );
    while(!s.empty()){
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        used[u] = 1;
        for(auto &v : adj(w, u)){
            if(cost[v] > w[u][v] && !used[v]){
                s.erase(make_pair(cost[v], v));
                cost[v] = w[u][v];
                s.insert(make_pair(cost[v], v));
            }
        }

    }
    sort(cost.begin()+1, cost.end());
    for(int i=0; i<q; ++i){
        int num;
        cin >> num;
        cout << cost[n-num] << '\n';
    }

}