#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> used;
vector<int> sol;

void permu(int n, int len){
    if(len < n){
        for(int i=1; i<=n; ++i){
            if(!used[i]){
                used[i] = 1;
                sol[len] = i;
                permu(n, len+1);
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
    cin >> n;
    sol.resize(n);
    used.resize(n);
    permu(n, 0);
}
