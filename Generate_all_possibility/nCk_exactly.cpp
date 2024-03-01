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
#include <iostream>
#include <vector>

using namespace std;

void combi(int n, vector<int> &sol, int len, int k, int chosen){
    if(len < n){
        //ex. 3C2 = 011, 110, ...
        //that means need to have exactly 2's 1 and 1's 0
        //-> n = 3, k = 2 means to have n-k = 1's 0 and k = 2's of 1
        //use k to keep track with 1 (and len - k is for track with 0)
        if(len - chosen < n - k){
            //need to have EXACTLY n - k of 0's
            sol[len] = 0;
            combi(n, sol, len+1, k, chosen);
        }
        if(chosen < k){
            sol[len] = 1;
            combi(n, sol, len+1, k ,chosen+1);
        }
        
    }else{
        for(int i=0; i<n; i++){
             cout << sol[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> sol(3);
    combi(3, sol, 0, 2, 0);
}
