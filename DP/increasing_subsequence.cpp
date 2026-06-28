#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vint array(n);
    for(auto& a:array) cin>>a;
    vint tails(1,array[0]);

    for(auto a:array){
        if(a>tails.back()) tails.push_back(a);
        else {
            auto it = lower_bound(tails.begin(),tails.end(),a);
            *it = a;
        }
    }
    cout<<tails.size()<<"\n";

    return 0;
}