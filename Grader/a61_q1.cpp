#include <bits/stdc++.h>

using namespace std;

long long p, k, A, B, num;

vector<long long> v;
long long perform(long long l, long long r){
    long long avenger_number = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    long long way_1 = avenger_number * (r-l+1) * B;
    if(avenger_number == 0) return A;
    if(r == l) return way_1;
    long long mid = (l+r)>>1;   
    long long x = perform(l, mid); 
    long long y = perform(mid+1, r);
    long long way_2 = x + y;
    return min(way_1, way_2);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   cin >> p >> k >> A >> B;
   long long arr_len = 1 << p;
   v.resize(k);
   for(long long i=0; i<k; ++i){
        int tmp;
        cin >> tmp;
        v[i] = --tmp; 
   }
   sort(v.begin(), v.end());
   cout << perform(0, arr_len-1);
}

