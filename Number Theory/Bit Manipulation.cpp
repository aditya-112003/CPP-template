#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printbinary(ll a){
    for(ll i=10;i>=0;i--){
        cout<<((a>>i) & 1);
    }cout<<'\n';
}


int main(){
   ll n=10;
   
   //Even Odd using bits

   if(n&1) cout<<"odd"<<'\n';   //generally faster tham n%2
   else cout<<"even"<<'\n';

   // divide / multiply 2

   cout<<(n>>1)<<" ";  //equivalent to divide 2
   cout<<(n<<1)<<'\n'; //equivalent to multiply 2 

   // upper to lower case and vice versa
   // 5th bit is unset in upper case and set in lower case

   char c = 'A';
   char e= c | (1<<5);
   cout<<char(c | (1<<5))<<'\n';
   cout<<char(e & ~(1<<5))<<'\n';

   // 1<<5 is ASCII value of space " "

   printbinary(' ');
   printbinary('_');
   
   cout<<char('A' |  ' ')<<'\n'; // to lowercase
   cout<<char('a' &  '_')<<'\n'; // to uppercase

   // unsetting bits upto i'th position
   
   ll i=4;
   printbinary(59);
   printbinary(59 & ~((1<<(i+1))-1)); // clear LSB upto ith pos
   i=3;
   printbinary(59 & (1<<(i+1))-1);    // clear MSB upto ith pos

   // check for 2 power

   if(n & n-1) cout<<"not 2 ki power"<<'\n';
   else cout<<"2 ki power"<<'\n';

   return 0;
}
