#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

const int MAXN=100005;
vector<pair<int,ll>> adj[MAXN];
ll dist[MAXN];
vbool visited(MAXN,false);

void bfs(int n=1){
    visited[n]=true;
    dist[n]=0;
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:adj[curr]){
            if(visited[neighbour.first] && dist[neighbour.first]>dist[curr]+neighbour.second){
                dist[neighbour.first]=dist[curr]+neighbour.second;
                q.push(neighbour.first);

            }
            else if(!visited[neighbour.first]){
                visited[neighbour.first]=true;
                dist[neighbour.first]=dist[curr]+neighbour.second;
                q.push(neighbour.first);
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
        int a,b;\
        ll c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    bfs(1);
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    cout<<"\n";

    return 0;
}