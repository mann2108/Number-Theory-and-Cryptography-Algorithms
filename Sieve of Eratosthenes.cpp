/// @author mann2108
/// Sieve of Eratosthenes O(n*loglog(n))

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<bool> primes(n+1,true);
        primes[0]=primes[1]=false;
        for(ll i=2;i<=n;i++){
            if(primes[i] and (i*i)<=n){
                for(ll j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
        for(ll i=0;i<n;i++){
            if(primes[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
