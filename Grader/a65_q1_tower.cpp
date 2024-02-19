#include <bits/stdc++.h>

using namespace std;

void perform(unordered_map<int, int> &m, vector<int> &v, int w){
    for(auto &i : v){
        int beg = i-w;
        int en = i+w;
        for(auto &j : m){
            if(j.first >= beg && j.first <= en){
                if(j.second-1 >= 0){
                    j.second--;
                    break;
                }
            }
            
        }
    }
    int ans = 0;
    for(auto &i : m) ans += i.second;
    cout << ans;
}
int main() {
  int n,m,k,w;
  cin >> n >> m >> k >> w;
  vector<int> tmp1(m), tmp2(m);
  unordered_map<int, int> mon;
  vector<int> tower(k);
  for(int i=0; i<m; ++i){
    cin >> tmp1[i];
  }
  for(int i=0; i<m; ++i){
    cin >> tmp2[i];
  }
  
  for(int i=0; i<m; ++i){
    mon[tmp1[i]] = tmp2[i];
  }
  for(int i=0; i<k; ++i){
    cin >> tower[i];
  }
  perform(mon, tower, w);
  
  
  
  

}