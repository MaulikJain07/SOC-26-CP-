#include<bits/stdc++.h>
using namespace std;

bool check_cow(int a_cows,vector<int>& pos,int dist){
    int cows_placed = 1;
    int last_pos = pos[0];

    for(int j=0;j<pos.size();j++){
        if(pos[j]-last_pos>=dist){
            cows_placed++;
            last_pos = pos[j];
        }
        if(cows_placed==a_cows) return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int testcase;
    cin>>testcase;
    for(int i=0;i<testcase;i++){

        int stalls,a_cows;
        cin>>stalls>>a_cows;

        vector<int> pos(stalls);
        for(int j=0;j<stalls;j++) cin>>pos[j];
        sort(pos.begin(),pos.end());

        int low=1;
        int high = pos[stalls-1] - pos[0];

        int max_min_dist = 0;

        while(low<=high){
            int mid = (low+high)/2;

            if(check_cow(a_cows,pos,mid)){
                max_min_dist = mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
        cout<<max_min_dist<<"\n";


    }

    return 0;
}