#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<bool> vbool;

int no_divisors(int n){
    int divisors=1;
    int k=n;
    for(int i=2;i*i<=n;i++){
        int count=1;
        while(k%i==0){
            count++;
            k=k/i;
        }
        divisors*=count;
    } 
    if(k>1) divisors=divisors*2;
    return divisors;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<no_divisors(n)<<"\n";
    }

    return 0;
}