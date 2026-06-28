#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> time;
    int a=-1;
    for(int i=0;i<2*n;i++){
        int input;
        cin>>input;
        time.push_back({input,-1*a});
        a=a*-1;
    }
    sort(time.begin(),time.end());

    int c = 0;
    int max_c=0;
    for(auto x:time){
        if(x.second==1) c++;
        else if(x.second==-1) c--;
        max_c = max(max_c,c);
    }
    cout<<max_c<<"\n";

    return 0;
}