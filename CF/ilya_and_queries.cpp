#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    int m;
    cin>>m;

    vector<pair<int,int>> queries(m);
    for(auto&q:queries){
        cin>>q.first;
        cin>>q.second;
    }
    vint binary(n,0),prefix(n+1,0);

    for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) binary[i]=1;

    for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + binary[i];

    

    for (auto q:queries){
        int i=q.first-1;
        int j=q.second-1;
        int count=prefix[j]-prefix[i];
        
        cout<<count<<"\n";
    }

    return 0;
}