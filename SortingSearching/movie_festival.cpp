#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>> movie_time(n);
    for(auto& m:movie_time){
        cin>>m.second;
        cin>>m.first;
    } 
    sort(movie_time.begin(),movie_time.end());
    int count=1;
    auto current = movie_time[0];
    for(int i=1;i<n;i++){
        auto next = movie_time[i];
        if(next.second>=current.first){
            count++;
            current = next;
        }
    }
    cout<<count<<"\n";
    return 0;
}