#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vint length(n);
    for(auto& l:length) cin>>l;
    sort(length.begin(),length.end());

    if(n%2==1){

        int final_length = length[(n-1)/2];
        ll sum=0;
        for(auto l:length) sum += (ll)abs(final_length-l);
        cout<<sum<<"\n";
    }

    else{

        int final_length_1 = length[n/2],final_length_2 = length[n/2-1];
        ll sum_1=0,sum_2=0;
        for(auto l:length){
            sum_1 += (ll)abs(final_length_1-l);
            sum_2 += (ll)abs(final_length_2-l);
        } 
        cout<<min(sum_1,sum_2)<<"\n";

    }


    return 0;
}