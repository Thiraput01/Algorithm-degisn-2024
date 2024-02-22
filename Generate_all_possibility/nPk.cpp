#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<bool> used;
vector<int> sol;

void permu(int n, int len, int k){
    if(len < k){
        for(int i=1; i<=n; ++i){
            if(!used[i]){
                used[i] = 1;
                sol[len] = i;
                permu(n, len+1, k);
                used[i] = 0;
            }
        }
    }else{
        for(auto &i : sol){
            cout << i;
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n >> k;
    sol.resize(k);
    used.resize(n+1);
    permu(n, 0, k);
}
