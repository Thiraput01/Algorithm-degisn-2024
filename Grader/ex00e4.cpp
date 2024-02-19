#include <bits/stdc++.h>

using namespace std;

void perform(int len, vector<int> &sol, int n, int k, int chosen){
    if(len < n){
        if(chosen < k){
            sol[len] = 1;
            perform(len + 1, sol, n, k, chosen + 1);
        }
        if(len - chosen < n - k){
            sol[len] = 0;
            perform(len + 1, sol, n, k, chosen);
        }

    }else{
        for(auto &i : sol){
            cout << i << "";
        }
        cout << "\n";
    }
}

int main() {
    int n,k;
    cin >> k >> n;
    vector<int> v(n);
    perform(0, v, n, k, 0);
}