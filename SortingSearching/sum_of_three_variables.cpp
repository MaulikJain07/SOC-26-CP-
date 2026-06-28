#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a;
    for(int i=1;i<=n;i++){
        int input;
        cin>>input;
        if(input<x-1) a.push_back({input,i});

    }
    sort(a.begin(),a.end());
    int length = a.size();
    if(length<3){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    if(x<a[0].first+a[1].first+a[2].first){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    // int i=0,j=1,k=2;
    // for(int i=0;i<length-2;i++){
    //     for(int j=i+1;j<length-1;j++){
    //         for(int k=j+1;k<length;k++ ){ 
    //             if(array[i].first+array[j].first+array[k].first==x){
    //                 cout<<array[i].second<<" "<<array[j].second<<" "<<array[k].second<<" "<<"\n";
    //                 return 0;
    //         }
    //     }
    //     }
    // }

    for(int i=0;i<length-2;i++){
        int sum = x - a[i].first;
        int j=i+1,k=length-1;
        while(j<k){
            if(a[j].first+a[k].first==sum){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<" "<<"\n";
                return 0;
            }
            else if(a[j].first+a[k].first>sum) k--;
            else j++;
        }
    }
    
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}