#include <bits/stdc++.h>

using namespace std;

int perform(vector<int> &v){
    int c = 0;
    for(int i=0; i<v.size(); ++i){
        for(int j=i; j<v.size(); ++j){
            if(v[i] > v[j]) c++;
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    int a = perform(v);
    cout << a;
}
