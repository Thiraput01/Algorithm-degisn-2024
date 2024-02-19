#include <bits/stdc++.h>

using namespace std;

int n, k;

bool check(vector<int> &v, int n){
    if(n == 2){
        return v[0] == 0 && v[1] == 1;
    }
    int mid = n/2;
    vector<int> f1(mid);
    vector<int> f2(mid);
    vector<int> b(mid);
    for(int i=0; i<mid; ++i){
        f1[i] = v[i];
        b[i] = v[i+mid];
        f2[mid-i-1] = v[i];
    }
    return (check(f1, mid) || check(f2, mid)) && check(b, mid);
}

int main() {
   cin >> n >> k;
   int a = pow(2, k);
   while (n--)
   {
        vector<int> v(a);
        for(int i=0; i<a; ++i){
            cin >> v[i];
        }
        bool ans = check(v, a);
        if(ans){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
   }
}
