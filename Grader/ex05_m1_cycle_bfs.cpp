#include <bits/stdc++.h>

using namespace std;

void print_graph(vector<vector<int>> &G){
    for(int i=0; i<G.size(); ++i){
        cout << i << ": ";
        for(auto j : G[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

bool check_bfs(vector<vector<int>> &G, int start){
    vector<bool> visited(G.size(), 0);
    queue<int> q;       
    q.push(start);
    visited[start] = 1;
    vector<int> parent(G.size(), -1);
    while (!q.empty()){
        int n = q.front();
        q.pop();
        for(auto &i : G[n]){
            if (!visited[i]) {
                visited[i] = 1;
                q.push(i);
                parent[i] = n;
            } else if (parent[n] != i) {
                return true;
            }
        }
    }
    return false;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n, e;
        cin >> n >> e;
        vector<vector<int>> G(n);
        while (e--){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool is_cyc = false;
        for(int i=0; i<n; ++i){
            if(check_bfs(G, i)){
                is_cyc = true;
                break;
            }
        }
        if(is_cyc) cout << "YES\n";
        else cout << "NO\n";
    }
}

