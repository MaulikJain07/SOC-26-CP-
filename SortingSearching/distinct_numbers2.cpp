#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if(!(cin>>n) || n==0){
        cout<<0;
        return 0;
    }

    unordered_set<int> numbers;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        numbers.insert(input);
    }

    cout<<numbers.size()<<"\n";

}