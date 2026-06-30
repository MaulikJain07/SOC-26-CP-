#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint vec(n);
    for(auto& v:vec) cin>>v;
    sort(vec.begin(),vec.end());
    int max_gcd=1;
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            max_gcd = max(max_gcd,gcd(vec[i],vec[j]));
        }
    }
    cout<<max_gcd<<"\n";
    return 0;
}