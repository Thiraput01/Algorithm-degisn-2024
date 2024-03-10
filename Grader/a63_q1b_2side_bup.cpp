#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> l(n), r(n);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int i=0; i<n; ++i) cin >> l[i];
    for (int i=0; i<n; ++i) cin >> r[i];

    for (int i=n-1; i>=0; --i) {
        for (int cases=0; cases<=1; ++cases) {
            for(int j=0; j<=k; ++j){
                  if (cases == 0) {
                    int a = l[i] + dp[min(n, i + w + 1)][1][min(k, j+1)]; //change side
                    int c = dp[i + 1][0][j];
                    dp[i][cases][j] = max(a, c);
            } else if (cases == 1) {
                    int b = r[i] + dp[min(n, i + w + 1)][0][min(k, j+1)]; //change side
                    int c = dp[i + 1][1][j];
                    dp[i][cases][j] = max(b, c);
            }
            }
          
        }
    }
    
    cout << max(dp[0][0][0], dp[0][1][0]);
}
