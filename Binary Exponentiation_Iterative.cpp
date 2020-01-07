#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


/**
Binary exponentiation (also known as exponentiation by squaring)
is a trick which allows to calculate an using only O(logn) multiplications
(instead of O(n) multiplications required by the naive approach).
*/


ll binExpo(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
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
