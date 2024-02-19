#include <bits/stdc++.h>
using namespace std;


int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  multiset<int> s;
  int n, q, a, b, qs;
  cin >> n >> q;
  while(n--){
    cin >> a >> b;
    for(register int i=0; i<b; ++i) s.insert(a);
  }
  //for(auto &i : s) cout << s << " ";
  while (q--)
  {
    cin >> qs;
    auto it = s.begin();
    advance(it, qs-1);
    cout << *it << "\n";
  }
}