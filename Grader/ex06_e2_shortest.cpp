#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, E, s;
    cin >> N >> E >> s;
    //s is start vertex
    vector<vector<int>> w(N, vector<int>(N, 0));
    vector<pair<int, int>> edges;
    vector<int> dist(N, 1e9);
    for(int i=0; i<E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(a, b));
        w[a][b] = c;
    }

    dist[s] = 0;
    for(int i=1; i<=N-1; ++i){
        for(auto &edge : edges){
            int u = edge.first;
            int v = edge.second;
            if(dist[u] + w[u][v] < dist[v]){
                dist[v] = dist[u] + w[u][v];
            }
        }
    }
    bool isnig = false;
    for(auto &edge : edges){
        int u = edge.first;
        int v = edge.second;
        if(dist[u] + w[u][v] < dist[v]){
            isnig = true;
        }
    }

    if(isnig){
        cout << -1 << "\n";
    }else{
        for(auto &d : dist){
            cout << d << " ";
        }
    }
    
}