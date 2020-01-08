#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll factWithMod(ll n,ll p){
    ll res=1;
    while(n>1){
        if((n/p)%2){
            res=(res*(p-1))%p;
        }
        else{
            res=(res*(1))%p;
        }
        for(ll i=2;i<=n%p;i++){
            res=(res*i)%p;
        }
        n/=p;
    }
    return res%p;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        cout<<factWithMod(n,p)<<endl;
    }
}
