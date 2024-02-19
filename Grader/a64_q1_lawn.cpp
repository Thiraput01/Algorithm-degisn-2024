#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    vector<long long> pfs(n + 1);
    for (long long i = 1; i <= n; i++) {
        cin >> pfs[i];
        pfs[i] += pfs[i - 1] + k;
    }
    
    while (m--) {
        long long a, b;
        cin >> a >> b;
        
        long long att = upper_bound(pfs.begin(), pfs.end(), pfs[a] + b) - pfs.begin() - 1;
        cout << pfs[att] - pfs[a] - (att - a) * k << "\n";
    }
    
    return 0;
}
