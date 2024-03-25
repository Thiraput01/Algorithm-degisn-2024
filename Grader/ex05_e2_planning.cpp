#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G; //direct graph
vector<int> indeg;

int main(){
    int n;
    cin >> n;
    G.resize(n);
    indeg.resize(n);
    for(int i=0; i<n; ++i){
        int m;
        cin >> m; 
        while(m--){
            int num;
            cin >> num;
            //G[i].push_back(num);
            G[num].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    //push in deg 0 first
    for(int i=0; i<n; ++i){
        if(!indeg[i]){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(auto &i : G[u]){
            indeg[i]--;
            if(!indeg[i]){
                q.push(i);
            }
        }
    }
    if(accumulate(indeg.begin(), indeg.end(), 0) != 0) cout << "Error";
    else{
        for(auto &i : ans) cout << i << " ";
    }


    // //print graph
    // for(int i=0; i<n; ++i){
    //     cout << i << ": ";
    //     for(auto &j: G[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "in deg vector ";
    // for(auto &i : indeg){
    //     cout << i << " ";
    // }
}