#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vint array(n);
    for(auto& a:array) cin>>a;
    sort(array.begin(),array.end());
    vector<pair<int,int>> queries(q);
    for(auto& qu:queries) {
        cin>>qu.first;
        cin>>qu.second;
    }
    vint diff(n+1,0),prefix(n+1,0);
    for(auto qu:queries){
        diff[qu.first-1] += 1;
        diff[qu.second] -= 1;
    }
    diff.pop_back();
    for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + diff[i];

    sort(prefix.rbegin(),prefix.rend());
    prefix.pop_back();
    sort(prefix.begin(),prefix.end());

    ll answer=0;
    for(int i=0;i<n;i++){
        answer+=((ll)array[i])*((ll)prefix[i]);
    }
    cout<<answer<<"\n";
    return 0;
}