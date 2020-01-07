#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;


/**
Binary exponentiation (also known as exponentiation by squaring)
is a trick which allows to calculate an using only O(logn) multiplications
(instead of O(n) multiplications required by the naive approach).
*/


ll binExpo(ll a,ll b){
    if(b==0)return 1;
    ll res = binExpo(a,b/2);
    if(b%2)return res*res*a;
    else return res*res;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        /// Computing a^b in O(log(n))
        cout<<binExpo(a,b)<<endl;
    }
}

