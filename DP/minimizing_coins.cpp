#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;
    vint coins(n),dp(x+1,1e7);
    for(auto& c:coins) cin>>c;
    sort(coins.begin(),coins.end());
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
            else break;
        }
        
    }
    if(dp[x]==1e7) cout<<-1<<"\n";
    else cout<<dp[x]<<"\n";
    return 0;
}