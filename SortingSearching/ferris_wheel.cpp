#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;  

    vector<int> weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    sort(weights.begin(),weights.end());

    int i=0,j=n-1,gondola=0;

    while(i<=j){
        if(weights[i]+weights[j]<=x){
            gondola++;
            i++;
            j--;
        }
        else{
            gondola++;
            j--;
        }
    }
    cout<<gondola<<"\n";
    return 0;
}