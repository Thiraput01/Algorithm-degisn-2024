#include <bits/stdc++.h>

using namespace std;

vector<int> v, s;

int getsum(int from, int to){
    return s[to] - s[from-1];
    //ex 3 to 5 = s[5] - s[2]
}

int mss(vector<int> &v, int l, int r){
    if(l==r) return v[l];
    int mid = (l+r) >> 1;
    int r1 = mss(v, l, mid);
    int r2 = mss(v, mid+1, r);
    int mxl = getsum(mid, mid);
    int mxr = getsum(mid+1, mid+1);
    //S[*][m] --> * = l to m
    for(int i=l; i<=mid; ++i){
        mxl = max(mxl, getsum(i, mid));
    }
    //S[m+1][*] --> * = m+1 to r
    for(int i=mid+1; i<=r; ++i){
        mxr = max(mxr, getsum(mid+1, i));
    }
    int r3 = mxl + mxr;
    return max(max(r1, r2), r3);
}

int main()
{
    int n;
    cin >> n;
    v.resize(n+1, 0);
    s.resize(n+1, 0);
    for(int i=1; i<=n; ++i){
        cin >> v[i];
        s[i] = s[i-1] + v[i];
    }
    int ans = mss(v, 1, n);
    cout << ans;
}