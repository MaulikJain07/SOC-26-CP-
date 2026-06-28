#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        tickets.insert(input);
    }

    vector<int> customers(m);
    for(int i=0;i<m;i++) cin>>customers[i];

    int output=-1;
    for(auto c: customers){
        auto iterator = tickets.upper_bound(c);
        if(iterator==tickets.begin()) cout<<output<<"\n";
        else{
            iterator--;
            cout<<*iterator<<"\n";
            tickets.erase(iterator);
        }

    }


    return 0;
}