#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<ll> values(n);
    for(int i=0;i<n;i++) cin>> values[i];

    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].first;
        cin>>queries[i].second;
    }
    vector<ll> prefix_sum(n+1);
    prefix_sum[0] = 0;
    ll sum =0;
    for(int i=1;i<=n;i++){
        sum+=values[i-1];
        prefix_sum[i] = sum;
    }
    for(auto q: queries){
        int l = q.first;
        int r = q.second;
        cout<<prefix_sum[r] - prefix_sum[l-1]<<"\n";
    }



    return 0;
}