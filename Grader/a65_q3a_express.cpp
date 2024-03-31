#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector< pair<int, int> >> &G){
    //find shortest from 1 to 2
    vector<int> cost(G.size(), 1e9);
    set< pair<int, int> > s; //{cost, node}
    s.insert( {0, 1} );
    cost[1] = 0;
    while(!s.empty()){
        int c = s.begin()->first;
        int u = s.begin()->second;
        s.erase(s.begin());
        //cout << "at node " << u << " ============= ";
        for(auto &p : G[u]){
            int w = p.second;
            int v = p.first;
            //cout << "checking " << v << ' ';
            if(w + c < cost[v]){
                s.erase( make_pair(cost[v], v) );
                cost[v] = w + c;
                s.insert( make_pair(cost[v], v) );
            }
        }
    }
    // cout << "finished dijkstra \n=================================\n";
    // for(auto d: cost){
    //     cout << d << " ";
    // }
    // cout << "\n";
    return cost[2];

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, w_12;
    cin >> n >> w_12;
    vector<vector< pair<int, int> >> G(n+1); //adjacent list {a, b, w} from 1 to n

    G[1].push_back({2, w_12}); G[2].push_back({1, w_12});

    for(int i=3; i<=n; ++i){
        int p;
        cin >> p;
        while(p--){
            int b, w;
            cin >> b >> w;
            G[i].push_back({b, w});
            G[b].push_back({i, w});
        }
        //print graph
        cout << dijkstra(G) << ' ';
        // for(int i=1; i<=n; ++i){
        //     cout << "node: " << i << ": ";
        //     for(auto j : G[i]){
        //         cout << "{" << j.first << ", " << j.second << "} ";
        //     }
        //     cout << "\n";
        // }
    }

}