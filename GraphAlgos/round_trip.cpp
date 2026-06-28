    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef vector<int> vint;
    typedef vector<bool> vbool;

    const int MAXN = 100005;
    vint adj[MAXN],parent(MAXN,0);
    vbool visited(MAXN,false);

    pair<int,int> dfs(int n){
        visited[n] = true;
        for(auto neighbour:adj[n]){
            // ek aise node neighbour ho jo visited ho aur uska parent bhi na ho, mtlb ek loop exist karta hai.
            if(visited[neighbour] && parent[n]!=neighbour) return {n,neighbour};
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = n;
                auto output = dfs(neighbour);
                if(output.first!=0 && output.second!=0) return output;
            }
        }
        return {0,0};
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
        pair<int,int> backEdge;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                backEdge = dfs(i);
                if(backEdge.first!=0 && backEdge.second!=0) break;
            } 
        }
        if(backEdge.first==0 && backEdge.second==0){
            cout<<"IMPOSSIBLE"<<"\n";       
            return 0;
        } 
        int element=backEdge.first;
        vint result;
        while(element!=backEdge.second){
            result.push_back(element);
            element = parent[element];
            
        }
        cout<<result.size()+2<<"\n"<<backEdge.second<<" ";
        
        for(auto r:result) cout<<r<<" ";
        cout<<backEdge.second<<"\n";


        return 0;
    }