#include <bits/stdc++.h>

using namespace std;

int x, n, k, tmp;

int perform(int x, int n, int k){
    if(n==1){
       return x % k;
    }
    if(n%2==0){
        tmp = perform(x, n/2, k);
        return (tmp * tmp) % k;
    }else{
        tmp = perform(x, n/2, k);
        tmp = (tmp * tmp) % k;
        return (tmp * (x%k)) % k;
    }

}

int main()
{
    cin >> x >> n >> k;
    cout << perform(x, n, k) << "\n";
}