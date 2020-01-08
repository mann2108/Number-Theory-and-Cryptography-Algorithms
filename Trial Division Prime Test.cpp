#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool is_prime(ll n){
    if(n<2)return false;
    if(n==2)return true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(is_prime(n))cout<<"PRIME"<<endl;
        else cout<<"NOT PRIME"<<endl;
    }
}
