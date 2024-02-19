#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,m;
    set<int> s;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int data;
        cin >> data;
        s.insert(data);
    }
    for (int i=0;i<m;i++){
        int num;
        bool found = false;
        cin >> num;
        for(auto it=s.begin(); it!=s.end(); it++){
            int target = num - *it;
            auto res = s.find(target);

            if ((res != s.end()) && res != it){
                found = true;
                break;
            }
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";

    }

}

