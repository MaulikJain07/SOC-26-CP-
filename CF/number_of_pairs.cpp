#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

ll pairs(vint& a,int target){
    ll count=0;
    for(int i=0;i<a.size();i++){
        auto it = upper_bound(a.begin()+i+1,a.end(),target-a[i]);
        count+=distance(a.begin()+i+1,it);
    }
    return count;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int testcase;
    cin>>testcase;

    for(int tc=0;tc<testcase;tc++){
        int n,l,r;
        cin>>n>>l>>r;
        vint array(n);
        for(auto& a:array) cin>>a;
        sort(array.begin(),array.end());

        cout<<pairs(array,r)-pairs(array,l-1)<<"\n";
    }

    return 0;
}