#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


/**
Binary exponentiation (also known as exponentiation by squaring)
is a trick which allows to calculate an using only O(logn) multiplications
(instead of O(n) multiplications required by the naive approach).
*/
ll mod = 1e9+7;

ll binExpo(ll a,ll b,ll m){
    cout<<m<<endl;
    a%=m;
    ll res=1;
    while(b>0){
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,m;
        cin>>a>>b>>m;
        /// Computing (a^b)%m in O(log(n))
        cout<<binExpo(a,b,m)<<endl;
    }
}
