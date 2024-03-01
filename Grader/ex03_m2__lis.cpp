#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; ++i){
        cin >> v[i];
    }
    vector<int> dp(n+1, 1);
    int lis = 0;
    for(int i=0; i<=n; ++i){
        for(int j=1; j<i; ++j){
            if(v[i] > v[j]){
                dp[i] = max(1, dp[j] + 1);
                lis = max(lis, dp[i]);
            }
        }
    }
    cout << lis;
}

