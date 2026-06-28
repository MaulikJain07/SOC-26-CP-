#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

const int MAXN = 100005;
vint adj[MAXN];
vector<bool> visited(MAXN,false);
int dist[MAXN];

void bfs(int node){
    queue<int> q;
    q.push(node);
    // dist[node]=0;
    visited[node] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int neighbour: adj[curr]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
            
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int islands=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i);
            islands++;
        }
            
    }

    
    cout<<islands<<"\n";
    
    return 0;
}