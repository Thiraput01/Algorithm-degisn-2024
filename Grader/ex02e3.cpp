#include <bits/stdc++.h>

using namespace std;

int perform(vector<int> &v, int num, int l, int r){
    if(l>=r) return v[r] <= num? r : -1;
    if(v[r] == num) return r;
    int mid = (l+r) >> 1;
    if(num >= v[mid+1]){
        return perform(v, num, mid+1, r);
    }else{
        return perform(v, num, l, mid);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    while(m--){
        cin >> num;
        int a = perform(v, num, 0, n-1);
        cout << a << "\n";
    }
    

}

