#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> tmp;

void merge(vector<int> &v, int l, int m, int r, vector<int> &tmp){
    //ex merging 4 3 6 , 1 7 2
    //           l      m+1  r 
    // = 1 2 3 4 6 7
    int bi = l;
    int ci = m+1;
    for(int i=l; i<=r; ++i){
        if(ci>r){
            tmp[i] = v[bi++];
            continue;
        }
        if(bi>m){
            tmp[i] = v[ci++];
            continue;
        }
        tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for(int i=l; i<=r; ++i) v[i] = tmp[i];
}
int merge_sort(vector<int> &v, int l, int r, vector<int> &tmp, int ans){
    if(l<r){
        int m = (l+r)>>1;
        int x = merge_sort(v, l, m, tmp, ans+1);
        int y = merge_sort(v, m+1, r, tmp, ans+1);
        merge(v, l, m, r, tmp);
        return  x + y;
    }
}

int main(){
    int n;
    cin >> n;
    v.resize(n);
    tmp.resize(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    int ans = 0;
    int uu = merge_sort(v, 0, n-1, tmp, ans);
    for(auto &i : v) cout << i << " ";
    cout << endl;
    cout << "merge count: " << uu;
}
