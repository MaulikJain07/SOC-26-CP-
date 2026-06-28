#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int cost(char a,char b){
    return (a==b) ? 0:1;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string pehla,dooja;
    cin>>pehla;
    cin>>dooja;
    int n1 = pehla.size(),n2 = dooja.size();

    vector<vint> edit_distance(n1+1,vint(n2+1,0));

    for(int i=0;i<=max(n1,n2);i++){
        if(i<=n1) edit_distance[i][0] = i;
        if(i<=n2) edit_distance[0][i] = i;
    }
    

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            edit_distance[i][j] = min(edit_distance[i-1][j]+1,edit_distance[i][j-1]+1);
            edit_distance[i][j] = min(edit_distance[i][j],edit_distance[i-1][j-1]+cost(pehla[i-1],dooja[j-1]));
        }
    }
    cout<<edit_distance[n1][n2]<<"\n";

    return 0;
}