#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>> memo;
int dfs(int l, int r){
    if(r-l <= 1 || r>=v.size()-1 || l<0) return max(v[l], v[r]);

    if(memo[l][r] != -1) return memo[l][r];

    int ll = max(v[l], v[l+1]) + dfs(l+2, r);
    int lr = max(v[l], v[r]) + dfs(l+1, r-1);
    int rr = max(v[r], v[r-1]) + dfs(l, r-2);
    int ans = max({ll, rr, lr});
    memo[l][r] = max(memo[l][r], ans);
    return memo[l][r];
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n; cin >> n;
    v.resize(n+1);
    memo.resize(n+1, vector<int>(n+1, -1));
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    int ans = dfs(0, n-1);
    cout << ans;
}

