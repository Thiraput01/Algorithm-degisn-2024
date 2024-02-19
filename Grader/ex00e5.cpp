#include <bits/stdc++.h>

using namespace std;

void perform(int len, vector<int> &sol, int n, int k){
    //cout << "in func\n";
    if(len < n){
        sol[len] = 0;
        perform(len+1, sol, n, k);
        sol[len] = 1;
        perform(len+1, sol, n, k);
        
    }else{
        int c = 0;
        int res = 0;
        for(int i=0; i<sol.size(); ++i){
            if(sol[i] == 0){
                c = 0;
            }else{
                c++;
                res = max(c, res);
            }
        }
        if(res>=k){
            for(auto &i : sol){
                cout << i;
            }
            cout << "\n";
        }
        
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    perform(0, v, n, k);
}