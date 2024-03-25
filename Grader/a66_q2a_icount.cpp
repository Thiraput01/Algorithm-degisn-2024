#include <bits/stdc++.h>
using namespace std;

vector<int> K;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }

    for(int i=0; i<m; ++i){
        int c = 0;
        int k; cin >> k;
        for(int j=0; j<n; ++j){
            if(v[j] == k) break;
            if(v[j] > k) c++;
            
        }
        if(c<0) c=0;
        cout << c << "\n";
    }
    
}
