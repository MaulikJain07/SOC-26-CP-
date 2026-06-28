#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

bool check_time(vint& prefix,int books,int t){
    int n = prefix.size();
    for(int i=0;i<n-books;i++){
        int time = prefix[i+books] - prefix[i];
        if(time<=t) return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin>>n>>t;
    vint time(n),prefix(n+1,0);
    for(auto& tt: time) cin>>tt;

    for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + time[i];

    int low=0,high=n,books=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(check_time(prefix,mid,t)){
            books = mid;
            low=mid+1;
        } 
        else high = mid-1;
    }
    cout<<books<<"\n";
    return 0;
}