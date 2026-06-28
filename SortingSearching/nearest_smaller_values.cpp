#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint num(n);
    for(auto& nu:num) cin>>nu;

    cout<<0<<" ";
    
    for(int i=1;i<n;i++){
        int index=0;
        for(int j=i-1;j>=0;j--){
            if(num[j]<num[i]) index = max(index,j+1);
        }
        cout<<index<<" ";
    }
    cout<<"\n";



    return 0;
}