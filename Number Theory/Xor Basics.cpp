#include<bits/stdc++.h>
using namespace std;
#define ll long long

// x^x ==0 and x^0==x

int main(){
    ll a,b;
    cin>>a>>b;
    
    //number swapping with xor
  
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;

    // find only element with odd frequency in O(1) space and O(n)time
  
    a=9;
    ll ans=0;
    for(ll i=0;i<a;i++){
        ll x; cin>>x;
        ans=ans^x;
    }
    cout<<ans;
    return 0;
}
