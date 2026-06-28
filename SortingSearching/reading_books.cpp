#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint time(n);
    for(auto& t:time) cin>>t;
    sort(time.begin(),time.end());

    ll time_sum=0;
    for(auto t:time) time_sum+=(ll)t;

    if(time[n-1]>=time_sum-time[n-1]) cout<<2*time[n-1]<<"\n";
    else cout<<time_sum<<"\n";
}