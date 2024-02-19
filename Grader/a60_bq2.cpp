#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<pair<int, int>> v;
vector<int> p;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
}
vector<int> pereto(int l, int r){
    if(l-r==1){
        vector<int> tmp;
        //two points
        if(v[l].first <= v[r].first && v[l].second <= v[r].second){
            tmp.push_back(l);
            return tmp;
        }else if(v[r].first <= v[l].first && v[r].second <= v[l].second){
            tmp.push_back(r);
            return tmp;
        }else{
            tmp.push_back(l);
            tmp.push_back(r);
            return tmp;
        }
    }
    if(l==r){
        //one point
        vector<int> tmp;
        tmp.push_back(l);
        return tmp;
    }
    int mid = (l+r) >> 1;
    vector<int> ans;
    vector<int> p_tmp;
    vector<int> p1 = pereto(l ,mid);
    vector<int> p2 = pereto(mid+1 ,r);
    for(auto &i : p1) p_tmp.push_back(i);
    cout << "PTMP IS: " ;
    print(p_tmp);
    for(auto &i : p2) p_tmp.push_back(i);
    cout << "PTMP IS: " ;
    print(p_tmp);
    for(int i=0; i<p_tmp.size()-1; ++i){
        //remember that x is already sorted
        if(v[p_tmp[i]].first > v[p_tmp[i+1]].second){
            ans.push_back(p_tmp[i]);
        }
    }
    return ans;

}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    vector<int> ans = pereto(0, n-1);
    cout << ans.size();
       
}
