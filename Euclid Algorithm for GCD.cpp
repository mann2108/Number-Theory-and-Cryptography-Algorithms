#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/**
GCD(a,b) is a if b is 0 else GCD(b,a%b)
*/

/// Iterative Implementation
ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

/// Recursive Implementation
ll gcd_recursive(ll a,ll b){
    if(b==0)return a;
    else return gcd_recursive(b,a%b);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        /// GCD(a,b) in O(log(min(a,b)))
        cout<<gcd(a,b)<<endl;
        cout<<gcd_recursive(a,b)<<endl;
    }
}

