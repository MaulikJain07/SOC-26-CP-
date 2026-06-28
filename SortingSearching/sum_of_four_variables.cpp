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
        if(input<x-2) a.push_back({input,i});

    }
    sort(a.begin(),a.end());
    int length = a.size();
    if(length<4){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    if(x<a[0].first+a[1].first+a[2].first){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }

    for(int i=0;i<length-3;i++){
        for(int j=i+1;j<length-2;j++){

            int sum = x - a[i].first-a[j].first;
            int k=j+1,w=length-1;
            while(k<w){
                if(a[k].first+a[w].first==sum){
                    cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<" "<<a[w].second<<" "<<"\n";
                    return 0;
                }
                else if(a[k].first+a[w].first>sum) w--;
                else k++;

        }
        
        }
    }
    
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}