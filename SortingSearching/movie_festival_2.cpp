#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> timings(n);
    for(auto& t:timings) cin>>t.second>>t.first;
    sort(timings.begin(),timings.end());

    multiset<int> end_time;
    while(k--) end_time.insert(0);

    int movie_count=0;
    for(auto t:timings){
        int start = t.second;
        auto it = end_time.upper_bound(start);
        if(it==end_time.begin()) continue;
        else{
            it--;
            end_time.erase(it);
            end_time.insert(t.first);
            movie_count++;
        }
    }
    cout<<movie_count<<'\n';
    return 0;
}