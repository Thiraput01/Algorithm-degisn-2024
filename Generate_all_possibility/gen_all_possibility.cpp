#include <iostream>
#include <vector>

using namespace std;

void combi(int n, vector<int> &sol, int len, int k, int chosen){
    if(len < n){
        sol[len] = 0;
        combi(n, sol, len+1, k, chosen);
        sol[len] = 1;
        combi(n, sol, len+1, k ,chosen+1);    
    }else{
        for(int i=0; i<n; i++){
             cout << sol[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> sol(3);
    combi(3, sol, 0, 2, 0);
}
