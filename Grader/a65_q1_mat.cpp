#include <bits/stdc++.h>
using namespace std;

int n;
 //testcase 1 1 --> search(mt, 3, 2, 0LL, 0LL, 7, 7);
long long search(vector<vector<long long>> &mt, long steps, long long r, long long c, bool neg){
        //if its 2x2 terminate
        //len = 2^(mt length - step)
        long long len = 1LL << (n-steps);
        if(n - steps == 1){
            return (neg)? -mt[r][c] : mt[r][c];
        }

        if (r < len / 2 && c < len / 2) {
            //zone 1 do nothing
            return search(mt, steps + 1, r, c, neg);
        } else if (r >= len / 2 && c < len / 2) {
            //zone 3 negative
            return search(mt, steps + 1, r - (len / 2), c, !neg);
        } else if (r < len / 2 && c >= len / 2) {
            //zone 2 transpose
            return search(mt, steps + 1, c - (len / 2), r, neg);
        } else {
            //zone 4 negative + transpose
            return search(mt, steps + 1, c - (len / 2), r - (len / 2), !neg);
        }

}
int main() {
    long long m, u, v, w, p;
    cin >> n >> m;
    vector< vector<long long >> mt(2, vector<long long> (2, 0));
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            cin >> mt[i][j];
        }
    }
    long long mt_siz = 1LL << n;
    while(m--){
        long long num_r, num_c;
        cin >> num_r >> num_c;
        cout << search(mt, 0LL, num_r-1, num_c-1, false) << "\n";
    }
   
}
