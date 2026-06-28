#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;


const int MAXN = 1007;
vector<vint> maze(MAXN,vint(MAXN,0));
vector<vector<char>> path(MAXN,vector<char>(MAXN));

vint bfs(vector<pair<int,int>> monsters_p, pair<int,int> end_pt){
    
    vint result;
    
    for(auto m:monsters_p){
        queue<pair<int,int>> q;
        q.push(m);
        vector<vint> visited(MAXN,vint(MAXN,0)),dist(MAXN,vint(MAXN,MAXN));
        visited[m.first][m.second]=1;
        dist[m.first][m.second]=0;
        bool found=false;

        if(m.first==end_pt.first && end_pt.second==m.second){
            result.push_back(0);
            continue;
        } 

        while(!q.empty()){
            bool break_middle = false;
            pair<int,int> curr = q.front();
            q.pop();

            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            char dirn[]={'U','D','L','R'};

            for(int i=0;i<4;i++){
                int new_r = curr.first + dr[i];
                int new_c = curr.second + dc[i];

                if(visited[new_r][new_c]==0 && maze[new_r][new_c]==1){
                    dist[new_r][new_c] = dist[curr.first][curr.second]+1;
                    visited[new_r][new_c]=1;
                    q.push({new_r,new_c});
                    if(m==monsters_p.back())path[new_r][new_c] = dirn[i];
                }  

                if(new_r==end_pt.first && new_c==end_pt.second) {
                    result.push_back(dist[new_r][new_c]);
                    break_middle = true;
                    break;
                } 
            }

            if(break_middle){found=true; break;}
            
        }
        if(!found) result.push_back(MAXN);
    }
    return result;
    
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    pair<int,int> player;
    vector<pair<int,int>> monsters_p,end_points;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.')maze[i][j]=1;
            if(c=='M'){
                monsters_p.push_back({i,j});
                maze[i][j]=1;
            }
            if(c=='A'){
                player={i,j};
                maze[i][j]=1;
            }

            if((j==1 || j==m || i==1 || i==n) && (c=='.' || c=='A' || c=='M')){
                end_points.push_back({i,j});
            }
        }
    }
    monsters_p.push_back(player);
    
    pair<int,int> exit={0,0};
    bool escape=false;
    for(auto e:end_points){
        auto dist = bfs(monsters_p,e);
        if(dist.size()==0) break;
        int player_dist = dist.back();
        dist.pop_back();
        if(dist.size()==0 && player_dist!=MAXN) {
            cout<<"YES"<<"\n";
            cout<<player_dist<<"\n";
            exit=e;
            escape=true;
            break;
        }
        else{
            sort(dist.begin(),dist.end());
            int monster_dist = dist[0];
            if(player_dist<monster_dist) {
                cout<<"YES"<<"\n";
                cout<<player_dist<<"\n";
                escape=true;
                exit=e;
                // return 0;
                break;
            }
        }
    }

    
    if(escape){
        string directions;
        int i=exit.first,j=exit.second;
        while(!(i==player.first && j==player.second)){
            directions.push_back(path[i][j]);
            if(path[i][j]=='R') j--;
            if(path[i][j]=='L') j++;
            if(path[i][j]=='U') i++;
            if(path[i][j]=='D') i--;
        }   
        reverse(directions.begin(),directions.end());
        cout<<directions<<"\n";
        return 0;
    }
    
    

    cout<<"NO\n";
    // auto dist=bfs(monsters_p,end_points[0]);
    // cout<<dist.size()<<"\n";
    // cout<<path[2][1]<<"\n";
    // cout<<end_points[0].first<<','<<end_points[0].second<<"\n";

    return 0;
}