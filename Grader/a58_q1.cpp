#include <bits/stdc++.h>
using namespace std;



bool perform(vector<long long> &v, int a){

    for(register int i=0; i<v.size()-2; ++i){
        int low = i + 1;
        int high = v.size() - 1;
        int target = a - v[i];
        while (low < high)
        {
            if(v[low] + v[high] == target){
                return true;
            }
            else if(v[low] + v[high] < target){
                low++;
            }else{
                high--;
            }   
        }
        
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (register int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    while (m--) {
        long long a;
        cin >> a;
        bool bb = perform(v, a);
        if(!bb){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}
