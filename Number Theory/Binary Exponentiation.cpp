#include<bits/stdc++.h>
using namespace std;
#define ll long long
const  int M=1e9+7;
const long long int N=1e18+7;

int binexprecur(int a , int b){
    if(b==0) return 1;
    int res = binexprecur(a,b/2); // ll is used so that res*res doens't exceeds the value of int 
    if(b&1){
        return (a*(res*1LL*res)%M)%M;
    }else {
        return (res*1LL*res)%M;
    }
}

int binExpiter(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%M;
        }a=(a*1LL*a)%M;
        b=b>>1;
    }return ans;
}

//if a<=10e18 or 2^1234 something i.e very large we a=a%1e18


// if M is large eg M<=10e18 something then we use binary multiplicaiton bcz now a*a will now be not be modded by M which is itself that can result in 10e18 * 10e18 which can lead to an overflow

int BinExpiter(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=binmultiply(ans,a);
        }a=binmultiply(a,a);
        b=b>>1;
    }return ans;
}

// so we do a+a+a+a.......... a times

int binmultiply(ll a , ll b){
    int ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%M;
        }a=(a+a)%M;
        b=b>>1;
    }return ans;
}

int main(){

    // binary exponentiation
    // double data type can store huge value but not accurately and pow(a,b) returns double , so we don't use double for accuracy issue , this is the reason we use binary exponentiation 

    //recursive approach
    int a=16,b=20;
    cout<<binexprecur(a,b)<<'\n';

    // iterative approach is better than recursive

    cout<<binExpiter(a,b)<<'\n';

    return 0;

}
