#include <bits/stdc++.h>

using namespace std;

int main(){
    int R, C;
    cin >> R >> C;
    vector<vector<int>> w(R, vector<int>(C, 0));
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin >> w[i][j];
        }
    }

    queue< pair<int, int> > q; // {i, j}
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    dist[0][0] = 0;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        //go up
        if(i-1>=0 && dist[i][j] + w[i-1][j] < dist[i-1][j]){
            dist[i-1][j] = dist[i][j] + w[i-1][j];
            //cout <<"the value updated! : "<< dist[i-1][j] << " \n";
            q.push(make_pair(i-1, j));
        }

        //go down
        if(i+1<R && dist[i][j] + w[i+1][j] < dist[i+1][j]){
            dist[i+1][j] = dist[i][j] + w[i+1][j];
            q.push(make_pair(i+1, j));
        }

        //go left
        if(j-1>=0 && dist[i][j] + w[i][j-1] < dist[i][j-1]){
            dist[i][j-1] = dist[i][j] + w[i][j-1];
            q.push(make_pair(i, j-1));
        }
        //go right
        if(j+1<C && dist[i][j] + w[i][j+1] < dist[i][j+1]){
            dist[i][j+1] = dist[i][j] + w[i][j+1];
            q.push(make_pair(i, j+1));
        }
        
    }

    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}