#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

void max_subsequence(vint& avail,vint num){
    int n = num.size();
    int prev_count=0;
    for(int i=0;i<n-1;i++){
        int count=0;
        vint temp = avail;

        if(avail[i]==1){
            temp[i]=0;
            count++;
            for(int j=i+1;j<n;j++){
                if(avail[j]==1){
                    if(num[j]>num[i]){
                        count++;
                        temp[j]=0;
                    }
                }
        }
        }
        if(count>prev_count) avail = temp;
        prev_count = count;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vint num(n),avail(n,1),zeros(n,0);
    for(auto& n:num) cin>>n;
    int count=0;
    while(avail!=zeros){
        max_subsequence(avail,num);
        count++;
    } 
    cout<<count<<"\n";


    return 0;
}