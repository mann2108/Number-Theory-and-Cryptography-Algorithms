/// @author mann2108
/// Fermats Little Theorem for finding multiplicative inverse.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
/**

a*x ~ 1 mod m
x = a^(-1)

Note:
Fermat Little theorem only works when m is prime !!

a^(-1) = (a^(m-2))%m

*/
const ll m = 1e9+7;

ll pow(ll a,ll b,ll m){
    a=a%m;
    ll res = 1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

ll aInverse(ll a){
    return pow(a,m-2,m);
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        cout<<aInverse(a)<<endl;
    }
}
