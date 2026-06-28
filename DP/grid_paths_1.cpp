#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m=1e9+7;
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));
    for(auto& row:grid){
        for(auto& element:row){
            char a;
            cin>>a;
            if(a=='*') element=-1;
            else element=0;
        } 
    }
    int a=1,b=1;
    for(int i=0;i<n;i++){
        
        if(grid[0][i]==-1) a = -1;
        if(grid[i][0]==-1) b = -1;
        grid[0][i] = a;
        grid[i][0] = b;
        
    }
    // for(auto& row:grid){
    //     for(auto& element:row){
    //         cout<<element<<" ";
    //     } 
    //     cout<<endl;
    // }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if((grid[i][j]==-1)||(grid[i-1][j]==-1 && grid[i][j-1]==-1)) continue;
            else if(grid[i-1][j]==-1) grid[i][j] = grid[i][j-1];
            else if(grid[i][j-1]==-1) grid[i][j] = grid[i-1][j];
            else grid[i][j] = grid[i][j-1] + grid[i-1][j];
            grid[i][j]%=m;
        }
    }
    int result = (grid[n-1][n-1]!=-1) ? grid[n-1][n-1]:0;
    cout<<result<<"\n";
    // for(auto& row:grid){
    //     for(auto& element:row){
    //         cout<<element<<" ";
    //     } 
    //     cout<<endl;
    // }
    return 0;
}