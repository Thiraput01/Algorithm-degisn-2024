#include <bits/stdc++.h>
using namespace std;

void perform(vector<int> &v, int k, int l, int r) {
    if (k == 1) return;
    int mid = (l + r) >> 1;
    swap(v[mid - 1], v[mid]);
    int kl = k / 2;
    int kr = k / 2;
    if (k / 2 % 2 == 0) {
        kl--;
        kr++;
    }
    perform(v, kl, l, mid);
    perform(v, kr, mid + 1, r);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    if (k > (n << 1) - 1 || k % 2 == 0) 
        cout << -1;
    else {
        perform(v, k - 1, 0, n - 1);
        for (auto &i : v) {
            cout << i << " ";
        }
    }
    return 0;
}
