#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n+1,{0,0});
    for(int i=1;i<n+1;i++) {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());

    int i=1,j=n;
    while(a[i].first+a[j].first!=x && i<j){
        if(a[i].first+a[j].first>x) j--;
        else i++;
    }
    if(i==j) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<a[i].second<<" "<<a[j].second<<"\n";

    return 0;
}