#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
vector<int> l, r;
int n, w, k;

int solve(int i, bool cases) {
    if (i >= n) {
        return 0;
    }
    if (memo[i][cases] != -1) {
        return memo[i][cases];
    }
    int result = -1;
    if (cases == 0) {
        int a = l[i] + solve(i + w + 1, 1); // go use right
        int c = solve(i + 1, 0); // not use
        result = max(a, c);
    } else if (cases == 1) {
        int b = r[i] + solve(i + w + 1, 0); // go use left
        int c = solve(i + 1, 1); // not use
        result = max(b, c);
    }
    memo[i][cases] = result;
    return result;
}

int main() {
    cin >> n >> w >> k;
    l.resize(n);
    r.resize(n);
    memo.resize(n, vector<int>(3, -1));

    for (int i = 0; i < n; ++i) cin >> l[i];
    
    for (int i = 0; i < n; ++i) cin >> r[i];
    //case 0 : left
    //case 1 : right
    int result = max(solve(0, 0), solve(0, 1));
    cout << result;
}
