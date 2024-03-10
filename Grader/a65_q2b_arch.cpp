#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<vector<int>> memo(501, vector<int>(501, INT_MAX));
vector<int> v;

int perform(int l, int r){
    if(l >= r) return 0;
    int res = memo[l][r];

    if(res == INT_MAX){
        res = 0;
        //res = max( res, perform(l+1,r), perform(l,r-1) )
        res = max(res, perform(l+1, r));
        res = max(res, perform(l, r-1));
        for(int i=l+1; i<r+1; ++i){
            auto val = v[l] * v[i] + ( perform(l+1, i-1) + perform(i+1, r) );
            res = max(res, val);
        }   
    }
    memo[l][r] = res;
    return res;
}
int main() {
//  testcases 
//  8
//  3 9 -1 4 -5 5 2 7
//    cin >> n;
    v.resize(8);
    // for(int i=0; i<n; ++i){
    //     cin >> v[i];
    // }
    v = {3, 9, -1, 4, -5, 5, 2, 7};
    int ans = perform(0, 8-1);
    cout << ans;
}