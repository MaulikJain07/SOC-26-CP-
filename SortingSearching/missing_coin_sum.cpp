#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint coins(n);
    for(auto& c:coins) cin >> c;

    sort(coins.begin(),coins.end());

    ll range = 0;
    for(auto c:coins){
        if ((ll)c<=range+1) range+=(ll)c;
        else {
            cout<<range+1<<'\n';
            return 0;
        }
    }
    cout<<range+1<<"\n";
    return 0;
}