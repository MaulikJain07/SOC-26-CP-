#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int n_books(vint& time,int t){
    int n = time.size();
    int left=0;
    int books=0,sum=0;

    for(int right=0;right<n;right++) {
        sum+=time[right];
        
        while(left<=right && sum>t){
            sum-=time[left];
            left++;
        }

        books = max(books,right-left+1);
    }

    return books;
}

    
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin>>n>>t;
    vint time(n);
    for(auto& t: time) cin>>t;
    
    cout<<n_books(time,t)<<"\n";

    return 0;
}