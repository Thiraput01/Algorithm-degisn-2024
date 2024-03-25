#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;

int main(){
    int r, c, t;
    cin >> r >> c >> t;
    v.resize(r, vector<int>(c, 0));
    vector<pair<int, int>> start;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> v[i][j];
            if(v[i][j] == 1){
                start.push_back(make_pair(i, j));
            }
        }
    }

    queue<pair<int, int>> q;
    for(auto &i : start){
        q.push(i);
    }
    q.push({-1, -1});
    int ans = 0;
    int level = -1;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        int i = u.first;
        int j = u.second;

        if(i==-1 && j==-1){
            level++;
            q.push({-1, -1});
            continue;
        }

        if(level == t) break;
        if(v[i][j] == 1) ans++;

        if(i-1>=0 && !v[i-1][j]){
            v[i-1][j] = 1;
            q.push(make_pair(i-1, j));
        }
        //down
        if(i+1<r && !v[i+1][j]){
            v[i+1][j] = 1;
            q.push(make_pair(i+1, j));
        }
        //left
        if(j-1>=0 && !v[i][j-1]){
            v[i][j-1] = 1;
            q.push(make_pair(i, j-1));
        }
        //right
        if(j+1<c && !v[i][j+1]){
            v[i][j+1] = 1;
            q.push(make_pair(i, j+1));
        }
    }
    cout << ans;
}