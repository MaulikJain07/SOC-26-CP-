#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> price_page(n);
    vint max_pages(x+1,0);

    for(auto& p:price_page) cin>>p.first;
    for(auto& p:price_page) cin>>p.second;
    sort(price_page.begin(),price_page.end());

    for(auto p:price_page){
        for(int j=x;j>=p.first;j--) max_pages[j] = max(max_pages[j], max_pages[j-p.first]+p.second); 
    }
    cout<<max_pages[x]<<"\n";

    return 0;
}