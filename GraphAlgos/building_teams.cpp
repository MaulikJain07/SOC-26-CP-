#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

const int MAXN = 100005;
vint adj[MAXN],teams(MAXN,0);

bool bfs(int n){
    queue<int> q;
    q.push(n);
    teams[n] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:adj[curr]){
            if(teams[curr]==teams[neighbour]) return false;
            else if(teams[neighbour]==0){
                teams[neighbour] = teams[curr]%2+1;
                q.push(neighbour);
            }
        }
    }
    return true;
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

    for(int i=1;i<=n;i++){
        if(teams[i]==0){
            bool b=bfs(i);
            if(b==false){
                cout<<"IMPOSSIBLE"<<"\n";
                return 0;
            }
        }

    }
    for(int i=1;i<=n;i++) cout<<teams[i]<<" ";
    cout<<"\n";
    return 0;
}