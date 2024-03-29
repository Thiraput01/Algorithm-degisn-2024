#include <bits/stdc++.h>

using namespace std;

vector<long long> adj(vector<vector<long long>> &w, long long u){
    vector<long long> res;
    for(int v=0; v<w.size(); ++v){
        if(w[u][v]!=-1) res.push_back(v);
    }
    return res;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> rd(n);
    vector<vector<long long>> w(n, vector<long long>(n, -1));
    for(int i=0; i<n; ++i){
        cin >> rd[i];
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            w[i][j] = rd[i] ^ rd[j];
        }
    }

    //prim's algo
    vector<long long> cost(n, -1);
    set< pair<long long, long long> , greater<pair<long long, long long>> > s; // {cost, v}
    vector<long long> used(n);
    s.insert({0, 0});

    while(!s.empty()){
        long long u = s.begin()->second;
        long long c = s.begin()->first;
        s.erase(s.begin());
        used[u] = true;
        for(auto &v : adj(w, u)){
            if(cost[v] < w[u][v] && !used[v]){
                s.erase( make_pair(cost[v], v) );
                cost[v] = w[u][v];
                s.insert( make_pair(cost[v], v) );
            }
        }
    }
    long long ans = 0;
    for(int i=1; i<n; ++i) ans += cost[i];
    cout << ans;
}
