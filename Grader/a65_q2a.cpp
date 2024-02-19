#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> m;
  int n, q, num, seq, ask;
  cin >> n >> q;
  for(int i=0; i<n; ++i){
    cin >> num >> seq;
    m[num] += seq;
  }
  //for(auto &i : m) cout << i.first << " : " << i.second << "\n";
  map<int,int> ans;
  int t = 0;
  for(auto &i : m){
    t += i.second;
    ans[t] = i.first;
  }
  while (q--)
  {
    cin >> ask;
    auto it = ans.lower_bound(ask);
    cout << it->second << "\n";
  }
}