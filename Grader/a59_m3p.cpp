#include <bits/stdc++.h>
using namespace std;

string s1, s2;

bool check(int l1, int r1, int l2, int r2){
    if(l1 >= r1 ){
        return s1[l1] == s2[l2];
    }

    int m1 = (l1+r1) >> 1;
    int m2 = (l2+r2) >> 1;
    cout << m1 << " " << m2 << "\n";
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        //  0             0           1             1
    bool cond1 = check(l1, m1, l2, m2) && check(m1, r1, m2, r2);
    bool cond2 = check(l1, m1, m2, r2) && check(m1, r2, l2, m2);
    
    return cond1 || cond2;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(check(0, s1.size(), 0, s1.size())){
        cout << "YES";
    }else{
        cout << "NO";
    }

}
