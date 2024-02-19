#include <bits/stdc++.h>
using namespace std;

bool combi(vector<int> &v, vector<int> &sol, int len, int n, int k, int chosen, int a){
    if(len<n){
        if(len-chosen < n-k){
            sol[len] = 0;
            combi(v, sol, len+1, n, k, chosen, a);
        }
        if(chosen < k){
            sol[len] = 1;
            combi(v, sol, len+1, n, k, chosen+1, a);
        }
    }else{
        int ans = 0;
        for(int i=0; i<n ;++i){
            if(sol[i]==1){
                ans += v[i];
            }
        }
        if(ans == a){
            return true;
        }
        return false;
    }
}

void perform(vector<int> &v, int n){

}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> sol(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    while(m--){
        int a;
        cin >> a;
        bool b = combi(v, sol, 0, n, 3, 0, a);
        cout << b? "Yes\n" : "No\n";
    }

}
