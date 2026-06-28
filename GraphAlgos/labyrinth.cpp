#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;


void bfs(pair<int,int>& start, pair<int,int>& end,vector<vint>& labyrinth,vector<vector<bool>>& visited, vector<vint>& dist,vector<vector<pair<int,int>>>& parent){
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    while(!q.empty()){
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int new_r = curr_r + dr[i];
            int new_c = curr_c + dc[i];
            if(labyrinth[new_r][new_c]==1 && !visited[new_r][new_c]){
                visited[new_r][new_c] = true;
                q.push({new_r,new_c});
                dist[new_r][new_c] = dist[curr_r][curr_c] + 1;
                parent[new_r][new_c] = {curr_r,curr_c};
            }
            if(new_r==end.first && end.second==new_c) return ;
        }
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    pair<int,int> start,end;
    vector<vector<pair<int,int>>> parent(n+2,vector<pair<int,int>>(m+2));
    vector<vint> labyrinth(n+2,vint(m+2,0)),dist(n+2,vint(m+2,0));
    vector<vector<bool>> visited(n+2,vector<bool>(m+2,false));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            char c;
            cin>>c;
            if(c=='.') labyrinth[i][j]=1;
            if(c=='A'){
                labyrinth[i][j]=1;
                start = {i,j};
            } 
            if(c=='B'){
                labyrinth[i][j]=1;
                end = {i,j};
            }
        }
    }


    bfs(start,end,labyrinth,visited,dist,parent);
    
    
    int path_length = dist[end.first][end.second];
    if(dist[end.first][end.second]==0) cout<<"NO"<<"\n";
    else {
        
        cout<<"YES"<<"\n"<<path_length<<"\n";

    string path;
    int curr_r = end.first,curr_c = end.second;
    while(path_length--){
        int new_r = parent[curr_r][curr_c].first,new_c = parent[curr_r][curr_c].second;
        if(new_c<curr_c) path.push_back('R');
        else if(new_c>curr_c) path.push_back('L');
        else if(new_r<curr_r) path.push_back('D');
        else path.push_back('U');
        curr_r = new_r;
        curr_c = new_c;
    }
    reverse(path.begin(),path.end());
    cout<<path<<"\n";
    }
    return 0;
}   