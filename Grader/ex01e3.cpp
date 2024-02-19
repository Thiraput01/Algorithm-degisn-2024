#include <bits/stdc++.h>

using namespace std;

int perform(vector<int> &v, int num, int l, int r){
    if(l>=r) return v[l] > num? -1: v[l];
    if(v[r] <= num) return v[r];
    int mid = (l+r) >> 1;
    if(num >= v[mid+1]){
        perform(v, num, mid+1, r);
    }else{
        perform(v, num, l, mid);
    }
}

int main()
{
    int n, m, num;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    while(m--){
        cin >> num;
        int ans = perform(v, num, 0, v.size()-1);
        cout << ans << "\n";
    }
}