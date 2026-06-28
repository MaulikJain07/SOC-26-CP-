#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check_time(ll time,vector<ll>& v,ll m){
    ll sum=0;
    for(int i=0;i<v.size();i++){
        sum+=time/v[i];
        if(sum>=m) return true;
    }
    
    return false;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;

    vector<ll> time(n);
    for(int i=0;i<n;i++) cin>>time[i];

    ll low = 0;
    ll high = 1e18;
    ll min_time=0;
    while(low<=high){
        ll mid = (high+low)/2;
        if(check_time(mid,time,m)) {
            min_time = mid;
            high=mid-1;
        }   
        else low = mid+1;
    }
    cout<<min_time<<"\n";

    return 0;   
}
