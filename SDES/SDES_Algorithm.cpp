/// SDES Encryption Algorithm

#include "SDES_Key_Generation.cpp"
#include<bits/stdc++.h>

using namespace std;

ll IP8[8] = {2,6,3,1,4,8,5,7};
ll IP8Inverse[8] = {4,1,3,5,7,2,8,6};
ll EP8[8] = {4,1,2,3,2,3,4,1};
ll S0[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
ll S1[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
ll P4[4]={2,4,3,1};
ll RightHalfRecall[4];

ll temp[8];
ll LeftHalf[4],RightHalf[4];

///SDES Round (Runs 2 Times)
ll* SDESRound(ll* Round1Message,ll* K){

    for(ll i=0;i<4;i++){
        LeftHalf[i]=Round1Message[i];
        RightHalf[i]=Round1Message[i+4];
    }

    ll RightEP8[8];

    for(ll i=0;i<8;i++){
        RightEP8[i]=RightHalf[EP8[i]-1];
    }

    for(ll i=0;i<8;i++){
        RightEP8[i]^=K[i];
    }

    ll LeftHalf_2[4], RightHalf_2[4];

    for(ll i=0;i<4;i++){
        LeftHalf_2[i]=RightEP8[i];
        RightHalf_2[i]=RightEP8[i+4];
    }

    ll row1 = LeftHalf_2[0]*2+LeftHalf_2[3]*1;
    ll col1 = LeftHalf_2[1]*2+LeftHalf_2[2]*1;

    ll row2 = RightHalf_2[0]*2+RightHalf_2[3]*1;
    ll col2 = RightHalf_2[1]*2+RightHalf_2[2]*1;

    ll SOut[4];

    ll num1 = S0[row1][col1];
    ll num2 = S1[row2][col2];

    switch(num1){
        case 0 : SOut[0]=0;SOut[1]=0;break;
        case 1 : SOut[0]=0;SOut[1]=1;break;
        case 2 : SOut[0]=1;SOut[1]=0;break;
        case 3 : SOut[0]=1;SOut[1]=1;break;
    }
    switch(num2){
        case 0 : SOut[2]=0;SOut[3]=0;break;
        case 1 : SOut[2]=0;SOut[3]=1;break;
        case 2 : SOut[2]=1;SOut[3]=0;break;
        case 3 : SOut[2]=1;SOut[3]=1;break;
    }

    for(ll i=0;i<4;i++)temp[i]=SOut[P4[i]-1];
    for(ll i=0;i<4;i++)SOut[i]=temp[i];

    for(ll i=0;i<4;i++){
        LeftHalf[i]^=SOut[i];
    }

    return LeftHalf;
}

int main(){

    pair<ll*,ll*> p1 = generateKeys();

    ll K1[8], K2[8];

    for(ll i=0;i<8;i++)K1[i]=p1.first[i];
    for(ll i=0;i<8;i++)K2[i]=p1.second[i];

    cout<<"\nKEY1"<<endl;
    for(ll i=0;i<8;i++)cout<<K1[i]<<" ";cout<<endl;

    cout<<"\nKEY2"<<endl;
    for(ll i=0;i<8;i++)cout<<K2[i]<<" ";cout<<endl;

    ll Round1Message[8];
    cout<<"\nEnter 8 Bits Plain Text:"<<endl;
    for(ll i=0;i<8;i++)cin>>Round1Message[i];

    ///Passing Message from IP8
    for(ll i=0;i<8;i++)temp[i]=Round1Message[IP8[i]-1];
    for(ll i=0;i<8;i++)Round1Message[i]=temp[i];

    for(ll i=4;i<8;i++)RightHalfRecall[i-4]=Round1Message[i];


    ///Round-1
    ll* Round1Result = SDESRound(Round1Message,K2);


    ///SAWAPER
    ll Round2Message[8];
    for(ll i=0;i<4;i++)Round2Message[i]=RightHalfRecall[i];
    for(ll i=4;i<8;i++)Round2Message[i]=Round1Result[i-4];

    for(ll i=0;i<4;i++)RightHalfRecall[i]=Round1Result[i];

    ///Round-2
    ll* Round2Result = SDESRound(Round2Message,K1);

    ll EncryptedText[8];
    for(ll i=0;i<4;i++)EncryptedText[i]=Round2Result[i];
    for(ll i=4;i<8;i++)EncryptedText[i]=RightHalfRecall[i-4];

    ///IP8-Inverse
    for(ll i=0;i<8;i++)temp[i]=EncryptedText[IP8Inverse[i]-1];
    for(ll i=0;i<8;i++)EncryptedText[i]=temp[i];

    ///Final Encrypted Message
    cout<<"\n8 Bits Encrypted Text:"<<endl;
    for(ll i=0;i<8;i++)cout<<EncryptedText[i]<<" ";
    cout<<endl;
}
