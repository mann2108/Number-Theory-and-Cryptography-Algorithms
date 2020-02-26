/// SDES KEY GENERATION ALGORITHM IMPLEMENTATION
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/// P-BOX of 8 and 10 bits
ll P10[10]={3,5,2,7,4,10,1,9,8,6};
ll P8[8]={6,3,7,4,8,5,10,9};
/// Circular Left Shift Operation
void leftShift1(ll *LS){
    ll temp=LS[0];
    for(ll i=0;i<4;i++)LS[i]=LS[(i+1)%5];
    LS[4]=temp;
}

pair<ll*,ll*>generateKeys(){

    ll KEY[10],LS1[5],LS2[5];

    ll input[10];
    cout<<"Enter 10 Bits KEY:"<<endl;
    for(ll i=0;i<10;i++)cin>>input[i];
    for(ll i=0;i<10;i++)KEY[i]=input[P10[i]-1];

    ///LS1(5-bits) + LS2(5-bits) = KEY(10-bits)
    for(ll i=0;i<10;i++){
        if(i<5) LS1[i]=KEY[i];
        else LS2[i%5]=KEY[i];
    }

    /// Circular Left Shift by 1 bit (LS1 and LS2).
    leftShift1(LS1);
    leftShift1(LS2);

    /// P8 - Mapping (K1-KEY)
    ll K1[8];

    for(ll i=0;i<10;i++){
        if(i<5) input[i]=LS1[i];
        else input[i]=LS2[i%5];
    }
    for(ll i=0;i<8;i++){
        K1[i]=input[P8[i]-1];
    }

    /// Circular Left Shift by 2 bits (LS1 and LS2).
    leftShift1(LS1);
    leftShift1(LS1);
    leftShift1(LS2);
    leftShift1(LS2);

    /// P8 - Mapping (K2)
    ll K2[8];
    for(ll i=0;i<10;i++){
        if(i<5) input[i]=LS1[i];
        else input[i]=LS2[i%5];
    }

    for(ll i=0;i<8;i++){
        K2[i]=input[P8[i]-1];
    }

    return {K1,K2};
}
