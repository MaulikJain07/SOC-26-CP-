#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int m = 1e9+7;
    vector<ll> solve(7,0);
    solve[0]=1;
    for(int i=1;i<=n;i++){
        if(i<=6)for(int k=1;k<=i;k++) solve[i] += solve[i-k];

        else{
            solve[i%7] = solve[(i-1)%7] + solve[(i-2)%7] + solve[(i-3)%7] + solve[(i-4)%7] + solve[(i-5)%7] + solve[(i-6)%7];
            solve[i%7] %= m;
        }
    }
    cout<<solve[n%7]<<"\n";

    return 0;
}