#include <bits/stdc++.h>

using namespace std;

long long perform(vector<long long> &v, queue<long long> &q){
    long long time = 0;
    while (!q.empty())  
    {
        for(int i=0; i<v.size(); ++i){
            if(q.empty()) return time;
            if(time % v[i] == 0){
                q.pop();
                if(q.empty()) return time;
            }
        }
        if(q.empty()) return time;
        time++;
    }
    return time;
    

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, a;
    cin >> n >> a;
    vector<long long> v(n);
    vector<long long> ask(a);
    for(long long i=0; i<n; ++i){
        cin >> v[i];
    }
    for(long long i=0; i<a; ++i){
        long long ask;
        cin >> ask;
        queue<long long> q;
        while(ask--){
            q.push(1);
        }
        cout << perform(v, q) << "\n";
    }
}

