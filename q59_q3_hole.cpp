#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> G(1001, vector<bool>(1001, 0));

int bfs(int b, int a){
    queue< pair<pair<int,int>, int> > q ;
    vector<vector<bool>> visited(G.size(), vector<bool>(G.size(), 0));
    vector<pair<int, int>> ways = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    q.push({{b, a}, 0});
    visited[b][a] = 1;
    int res = INT_MAX;
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int c = q.front().second;
        q.pop();

        for(auto &way : ways){
            int nX = x + way.second;
            int nY = y + way.first;

            //base case
            if(nX<=0 || nY<=0 || nX>1000 || nY>1000){
                res = min(res, c);
                break;
            }
            if(nX>=1 && nY>=1 && nX<=1000 && nY<=1000){
                if(!visited[nY][nX]){
                    if(G[nY][nX]){
                        q.push({{nY, nX}, c+1});
                    }else{
                        q.push({{nY, nX}, c});
                    }

                    visited[nY][nX] = true;
                }
            }
        }
    }

    return res;
}


int main(){
    int n, a, b;
    cin >> n >> a >> b;
    G[b][a] = 1;
    while(n--){
        int x, y;
        cin >> x >> y;
        G[y][x] = 1;
    }
    int ans = bfs(b, a);
    cout << ans;
}