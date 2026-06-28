#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int v_digits(int n){
    vint digits;
    while(n!=0){
        digits.push_back(n%10);
        n = (n - n%10)/10;
    }
    sort(digits.begin(),digits.end());
    return *(digits.end()-1);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int count=0;
    while(n!=0){
        int max = v_digits(n);
        n -= max;
        count++;
    }
    cout<<count<<"\n";
    return 0;
}