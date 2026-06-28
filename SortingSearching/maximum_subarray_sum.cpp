#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<ll> a(n),dynamic(n);

    for(auto& aa:a) cin>>aa;
    ll max_sum = a[n-1];
    dynamic[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        
        dynamic[i] = max(dynamic[i+1]+a[i],a[i]);
        max_sum = max(dynamic[i],max_sum);

    }
    cout<<max_sum<<"\n";

    return 0;
}