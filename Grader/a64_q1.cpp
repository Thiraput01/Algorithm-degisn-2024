#include <iostream>
#include <vector>

using namespace std;

vector<int> f(100,-1);

void permu(int n,vector<int> &sol,int len, vector<bool> &used) {
  if (len < n) {
    for (int i = 0;i < n;i++) {
      if (!used[i] && (f[i] == -1 || used[f[i]])) {
       // if(f[i] != -1 && !used[f[i]]) continue;
        used[i] = true;
        sol[len] = i;
        permu(n,sol,len+1,used);
        used[i] = false;
      }
    }
  } else {
    for (int i = 0;i < n;i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n,m, a, b;
  cin >> n >> m;
  for (int i = 0;i < m;i++) {
    cin >> a >> b;
    f[b] = a;
  }

  vector<int> sol(n);
  vector<bool> used(n);
  //f.resize(100);
  permu(n,sol,0,used);

}