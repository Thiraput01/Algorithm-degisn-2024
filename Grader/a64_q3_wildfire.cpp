#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G; //directed graph
vector<int> days, cost;
vector<bool> burnt; //if true = burnt
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    G.resize(n);
    days.resize(k);
    cost.resize(n);
    burnt.resize(n, 0);
    for(int i=0; i<n; ++i) cin >> cost[i];
    for(int i=0; i<k; ++i) cin >> days[i];
    while(m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // for(int i=0; i<n; ++i){
    //     cout << i << ": ";
    //     for(auto j : G[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    for(auto &i:days){
        if(!burnt[i]){
            burnt[i] = true;
            queue<int> q;
            q.push(i);
            //burn all the adjacent
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto &j: G[u]){
                    if(!burnt[j]){
                        burnt[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        int price = 0;
        //cout << "day:" << i <<", burnt: ";
        // for(auto k : burnt) cout << k << " ";
        // cout << "\n";
        for(int j=0; j<n; ++j){
            if(!burnt[j]) price += cost[j];
        }
        cout << price << " ";
    }
}