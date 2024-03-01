#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m;
vector<int> v(11, 0);
vector<vector<int>> dp(10001, vector<int>(10001, INF));

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> v[i];
    dp[0][0] = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            for(int k=1; k<=100; ++k){
                if(j - k*k < 0) break;
                int diff = v[i] - k;
                dp[i][j] = min( dp[i][j], dp[i-1][j-(k*k)] + diff*diff );
            }
        }
    }
    int ans = dp[n][m]==INF? -1: dp[n][m];
    cout << ans;
}