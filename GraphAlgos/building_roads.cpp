#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

const int MAXN = 100005;
vector<int> adj[MAXN];
vbool visited(MAXN,false);

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:adj[curr]){
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
    vector<int> disj_nodes;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            disj_nodes.push_back(i);
            islands++;
            bfs(i);
        }
    }
    cout<<islands-1<<"\n";
    for(int i=1;i<islands;i++){
        cout<<disj_nodes[0]<<" "<<disj_nodes[i]<<"\n";
    }

    return 0;
}