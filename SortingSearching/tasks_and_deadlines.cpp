#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vint deadline(n);
    vector<ll> duration(n);
    for(int i=0;i<n;i++) cin>>duration[i]>>deadline[i];
    sort(duration.begin(),duration.end());
    sort(deadline.begin(),deadline.end());
    ll sum=0;
    for(auto& d:duration){
        sum+=d;
        d = sum;
    }

    ll reward = 0;
    for(int i=0;i<n;i++){
        reward += ((ll)deadline[i] - duration[i]);
    }
    cout<<reward<<"\n";
    return 0;
}