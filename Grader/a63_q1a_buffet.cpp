#include <bits/stdc++.h>

using namespace std;

int n, K, m, p, w;
vector<int> d(200001, 0);

void solve(int p, int w){
    int cur = d[p];
    int prev = 0;
    for(int i=p; i<=n; ++i){
        cur = prev + d[i] - m;
        if(cur >= w){
            cout << i << "\n";
            return;
        }
        prev = cur;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> K >> m;
     for(int i=1; i<=n; ++i){
        cin >> d[i];
    }
    for(int i=0; i<K; ++i){
        cin >> p >> w;
        solve(p, w);
    }
}
