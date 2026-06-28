#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

const int MAXN = 100005;
vector<int> adj[MAXN],comp(MAXN,0),parent(MAXN,0);

void bfs(int n=1){
    queue<int> q;
    comp[n]=1;
    q.push(n);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:adj[curr]){
            if(comp[neighbour]==0){
                comp[neighbour] = comp[curr]+1;
                q.push(neighbour);
                parent[neighbour] = curr;
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

    bfs();
    int c = comp[n];
    if(c==0) cout<<"IMPOSSIBLE"<<"\n";
    else{
        cout<<c<<"\n";
        int path[c];
        path[c-1] = n;
        for(int i=c-2;i>=0;i--){
            path[i] = parent[path[i+1]];
        }
        for(auto p:path) cout<<p<<" ";
        cout<<"\n";
    }

    return 0;
}