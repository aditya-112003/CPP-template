#include<bits/stdc++.h>
using namespace std;
#define ll long long

// 2 power 4 is 1<<4
// set bit =1 , unset bit =0
// set bits are cheecked as 0 base indexing eg. 0th bit set , 1st bit set etc
// ~ tilda operator i.e complement of all bits eg. 1000 to 0111 


void printbinary(ll a){
    for(ll i=10;i>=0;i--){
        cout<<((a>>i) & 1);
    }cout<<'\n';
}

int main(){
    int a=(1ll<<31)-1;
    unsigned int b=(1ll<<32)-1;
    cout<< INT_MAX <<endl;
    cout<<a<<" "<<b<<'\n';

    printbinary(13);
    int n=13;
    int i=4;
    if((n & (1<<i))!=0) cout<<"Set"<<'\n';
    else cout<<"Unset"<<'\n';

    //setting a bit
  
    printbinary(n | 1<<i);
    
    //unsetting a bit
  
    printbinary(n & ~(1<<i));

    //toggle bit
  
    printbinary(n ^ (1<<i));
  
    //counting the set bits
    ll ct=0;
    for(ll i=31;i>=0;i--){
        if((n & (1<<i))!=0) ct++; 
    }cout<<ct<<'\n';

    cout<<__builtin_popcount(n)<<'\n';         // gives no. of set bits
    cout<<__builtin_popcountll((1LL<<35)-1)<<'\n';

    // GCD and LCM of a number 
    
    gcd=__gcd(a,b);
    lcm = a*b/(__gcd(a,b);
    
    return 0;
}
