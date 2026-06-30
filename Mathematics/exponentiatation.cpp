#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

int expo(int a,int b,int m=1e9+7){
    if(b==0) return 1;
    if(a==0 && b!=0) return 0;
    ll u = expo(a,b/2,m);
    u = (u*u)%m;
    if(b%2==1) u = (a*u)%m;
    return u;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin>>c;
    while(c--){
        int a,b;
        cin>>a>>b;
        cout<<expo(a,b)<<"\n";

    }

    return 0;
}