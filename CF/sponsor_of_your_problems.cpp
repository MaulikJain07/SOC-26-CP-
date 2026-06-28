#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int common_digits(int l,int r){
    vint diff;
    while(l!=0){
        diff.push_back(r-l);
        r=r/10;
        l=l/10;

    }
    sort(diff.begin(),diff.end());
    int zeros=0,ones=0;
    for(auto d:diff){
        if(d==0) zeros++;
        else if(d==1) ones++;
        else if(d>1) break;
    }
    return 2*zeros+ones;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        
        int l,r;
        cin>>l>>r;
        cout<<common_digits(l,r)<<"\n";

    }

    return 0;
}