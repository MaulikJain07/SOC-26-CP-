#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> numbers(n);
    
    for(int i=0;i<n;i++) cin>>numbers[i];
    sort(numbers.begin(),numbers.end());
    
    int start = numbers[0];
    int count = 1;
    for(auto number : numbers){
        if(start != number){
            count++;
            start = number;
        }
        else continue;
    }
    cout <<count<<"\n";
    return 0;
}