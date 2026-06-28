#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

struct Project{
    int start,end,reward;
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<Project> projects(n);
    vector<ll> dp(n);
    for(auto& p:projects)cin>>p.start>>p.end>>p.reward;
    
    sort(projects.begin(),projects.end(),[](Project& a,Project& b){
        if(a.end==b.end) return a.start<b.start;
        return a.end<b.end;
    });
    dp[0] = projects[0].reward;
    
    for(int i=1;i<n;i++){
        int current_start = projects[i].start;
        auto it = lower_bound(projects.begin(),projects.begin()+i,current_start,[](Project& p,int target){
            return p.end < target;
        });
        if(it==projects.begin()) dp[i] = max(dp[i-1],(ll)projects[i].reward);
        else {
            dp[i] = max(dp[i-1],(ll)projects[i].reward+dp[it-1-projects.begin()]);
        }
    }
    sort(dp.begin(),dp.end());
    cout<<dp[n-1]<<"\n";
    return 0;
}   