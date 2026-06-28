#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desired(n);
    for(int i=0;i<n;i++) cin>>desired[i];


    vector<int> apartment(m);
    for(int j=0;j<m;j++)cin>>apartment[j];

    sort(desired.begin(),desired.end());
    sort(apartment.begin(),apartment.end());

    int i=0,j=0,match=0;

    while(i<n && j<m){
        if(abs(apartment[j]-desired[i])<=k){
            match++;
            i++;
            j++;
        }
        else if(apartment[j]>desired[i]+k) i++;
        else j++;

    }
    cout<<match<<"\n";
    return 0;
}