#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> &v, int &v_sum){
    int cur_sum = 0;
    int mss = v[0];
    for(auto &i : v){
        cur_sum += i;
        v_sum += i;
        mss = max(cur_sum, mss);
        cur_sum = max(cur_sum, 0);
    }
    return mss;
}

int main() {
    int n;
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    //kadane
    int v_sum = 0;
    int case_1 = cal(v, v_sum);
    for(int i=0; i<n; ++i) v[i] = -v[i];
    int dontuse = 0;
    int case_2 = v_sum + cal(v, dontuse);
    int maxsum = max(case_1, case_2);
    cout << ((case_2!=0)? maxsum : case_1);
}