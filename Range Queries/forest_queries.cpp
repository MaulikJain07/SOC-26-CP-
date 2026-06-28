#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<vint> forest(n,vint(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char input;
            cin>>input;
            if(input=='.') forest[i][j] = 0;
            else if(input == '*') forest[i][j] = 1;
        }
    }
    vector<vint> queries(q,vint(4));
    for(int i=0;i<q;i++){
        for(int j=0;j<4;j++){
            cin>>queries[i][j];
        }
    }

    vector<vint> sum(n,vint(n+1));
    for(int i=0;i<n;i++){
        sum[i][0] = 0;
        int prefix_sum = 0;

        for(int j=0;j<n;j++){
            prefix_sum += forest[i][j];
            sum[i][j+1] = prefix_sum;
        }
    }

    for(auto q : queries){
        int trees = 0;
        for(int y=q[0]-1;y<=q[2]-1;y++){
            int row_trees = sum[y][q[3]] - sum[y][q[1]-1];
            trees+=row_trees;
        }
        cout<<trees<<"\n";
    }


    return 0;
}