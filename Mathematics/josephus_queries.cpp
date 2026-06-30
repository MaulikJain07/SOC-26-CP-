#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

int josephus(int n,int k,int first){ // first ki value ya toh -1 hogi ya 0, jab -1 toh first element hai jab 0 toh 2nd.
    if(n==1) return n;
    if(2*k+first<=n) return 2*k+first;
    if(n%2==0) return 2*josephus(n-n/2,k-n/2,first)-abs(first+1);
    else return 2*josephus(n-n/2+first,k-n/2+first,-abs(first+1))-abs(first+1);
    return 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        cout<<josephus(n,k,0)<<"\n";
    }

    return 0;
}