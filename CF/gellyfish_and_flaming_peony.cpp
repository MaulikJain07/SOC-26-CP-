#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

int vector_gcd(vint array){
    int hcf = array[0];
    int n = array.size();
    for(int i=1;i<n;i++){
        hcf = gcd(hcf,array[i]);
    }
    return hcf;
}

pair<vint,int> gcd_vector(vint array){
    pair<vint,int> result;
    vint gcd_array;
    int n = array.size();
    if(n==1){
        result.first = array;
        result.second = array[0];
        return result;
    }
    int min_gcd = array[n-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            gcd_array.push_back(gcd(array[i],array[j]));
            min_gcd = min(min_gcd,gcd(array[i],array[j]));
        } 
    }
    result.first = gcd_array;
    result.second = min_gcd;
    return result;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vint array(n);
        multiset<int> arr_set;
        for(auto& a:array){
            int input;
            cin>>input;
            a=input;
            arr_set.insert(input);
        } 
        sort(array.begin(),array.end());
        
        int hcf = vector_gcd(array);
        if(arr_set.find(hcf)!=arr_set.end()) cout<<n-arr_set.count(hcf)<<"\n";
        else{
            int count=1;
            while(gcd_vector(array).second!=hcf){
                array = gcd_vector(array).first;
                count++;
            }
            cout<<n-1+count<<"\n";
        }

    }

    return 0;
}