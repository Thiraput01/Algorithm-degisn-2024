#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<float>> &w){
    for(int n=0; n<w.size(); ++n){
        for(int i=0; i<w.size(); ++i){
            for(int j=0; j<w.size(); ++j){
                w[i][j] = max(w[i][j], w[i][n]*w[n][j]);
            }
        }
    }
    for(int i=0; i<w.size(); ++i){
            for(int j=0; j<w.size(); ++j){
                if(w[i][j] * w[j][i] > 1) return true;
            }
        }
    return false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<vector<float>> w(m, vector<float>(m, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j){
                cin >> w[i][j];
            }
        }
        
        bool ok = check(w);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}