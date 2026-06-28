#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int n_shops(vint& price, int m){
    int n = price.size();
    int shops=0;
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(price[mid]<=m){
            shops = mid+1;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }   
    return shops;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint bar_price(n);
    for(auto& p : bar_price) cin>>p;
    sort(bar_price.begin(),bar_price.end());

    int q;
    cin>>q;
    vint av_money(q);
    for(auto& m : av_money) cin>>m;

    for(auto m:av_money) cout<<n_shops(bar_price,m)<<"\n";


    return 0;
}