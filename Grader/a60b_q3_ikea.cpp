#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> &inG, vector<int> &tmp){
    vector<bool> done(inG.size(), 0);
    for(auto &i : tmp){
        done[i] = true;
        for(auto &k : inG[i]){
            if(!done[k]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> inG(n+1); //directed graph
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        inG[b].push_back(a);
    }
    // for(int i=1; i<=n; ++i){
    //     cout << i << " : ";
    //     for(auto j : inG[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=0; i<5; ++i){
        vector<int> tmp(n);
        for(int j=0; j<n; ++j){
            cin >> tmp[j];
        }

        bool suc = check(inG, tmp);
        if(suc) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }
}