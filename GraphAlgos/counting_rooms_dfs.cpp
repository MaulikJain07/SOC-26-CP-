#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vint;
 
 void dfs(int r,int c,vector<vector<bool>>& visited,vector<vint>& graph){
    visited[r][c]=true;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int new_r = r+dr[i];
        int new_c = c+dc[i];
            if(!visited[new_r][new_c] && graph[new_r][new_c]==1){
                visited[new_r][new_c] = true;
                dfs(new_r,new_c,visited,graph);
        }
    }
 }
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<vint> graph(n+2,vint(m+2,0));
    vector<vector<bool>> visited(n+2,vector<bool>(m+2,false));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            char c;
            cin>>c;
            if(c=='.') graph[i][j]=1;
        }
    }
    int rooms=0;
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(!visited[i][j] && graph[i][j]==1){
                rooms++;
                dfs(i,j,visited,graph);
            }
        }
    
    }
    cout<<rooms<<"\n";
 
    return 0;
}
