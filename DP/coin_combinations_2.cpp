#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    int m =1e9+7;
    cin>>n>>x;
    
    vint coins(n),sum(x+1,0);
    for(auto& c:coins) cin>>c;
    sum[0]=1;

    for(auto c:coins){
        for(int i=0;i<x+1;i++){
            if(i-c>=0) {sum[i] += sum[i-c];sum[i]%=m;}
        }
    }
    cout<<sum[x]<<"\n";
    return 0;
}