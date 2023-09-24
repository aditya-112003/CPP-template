#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    //To find the prime factors of a number in optimised way O(sqrt(n))  

    ll m;
    cin>>m;
    bool isPrime = true;
    vector<ll> primeFactors;
    for(ll i=2;i * i<=m;i++){
        while(m%i==0){
            primeFactors.push_back(i);
            m/=i;
        }
    }
    if(m>1){
        primeFactors.push_back(m);
    }    
    for(auto i: primeFactors) cout<<i<<" ";
    cout<<'\n';


    //Divisors of a number can be found in O(sqrt(n)) time using this loop.
    // x= p1^n1 * p2^n2 * p3^n3 ... where p are the prime factors of x and n is its exponent.
    //total number of divisors of x will be (n1+1)*(n2+1)*(n3+1).... where n1,n2,n3 are the exponents of the prime factors.
    //sum of all divisors we just add all the possibilites 
    // In this case it will be p1^(n1+1)/p1-1 + p2^(n2+1)/p2-1 + p3^(n3+1)/p3-1 ..... and so on uptill all prime factors . 

    ll n=3;
    cin>>n;
    ll ct=0;
    ll sum=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" "<<n/i<<"\n";
            ct++;
            sum+=i;
            if(i!=n/i) {
                sum+=n/i;
                ct++;
            }
        }
    }
    cout<<sum<<"\n";
    cout<<ct<<"\n";

    //SIEVE Algorithm 
    //Find the prime numbers upto a given number in O(n(log(log(n)))) time complexity.

    ll k = 1e7 + 10;
    vector<bool> isPrimeVector(k,true);
    isPrimeVector[0] = isPrimeVector[1] = false;
    for(ll i=2;i<k;i++){
        if(isPrimeVector[i]==true){
            for(ll j=2*i;j<k;j+=i){
                isPrimeVector[j] = false;    
            }
        }
    }
    for(ll i=1;i<100;i++){
        cout<<isPrimeVector[i]<<' ';
    }

    
    //Some Sieve Variations 

    // lowest prime and highest prime

    vector<ll> lp(k,0),hp(k,0);
    for(ll i=2;i<k;i++){
        if(isPrimeVector[i]==true){
            lp[i]=i;
            hp[i]=i;
            for(ll j=2*i;j<k;j+=i){
                isPrimeVector[j] = false;    
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }
    for(ll i=2;i<25;i++){
        cout<<lp[i]<<' '<<hp[i]<<'\n';
    }

    //prime factorisation in log(n)
    //this method can deal in log n because one prime is already precomputed ( hp[n] ) and that's all we need to get the other prime factors usefull in query

    ll num;
    vector<ll> prime_factors;
    while(n>1){
        ll prime_factor = hp[num];
        while(num%prime_factor==0){
            num/=prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }

    //for Divisors N log(N)
    // again this method is useful when queries are given many and u have to store divisors upto given N 

    ll number=1e5+10;

    vector<ll> divisors[number];
    for(ll i=2;i<number;i++){
        for(ll j=i;j<number;j+=i){
            divisors[j].push_back(i);
        }
    }
    for(ll i=0;i<10;i++){
        for(auto j : divisors[i]){
            cout<<j<<" ";
        }cout<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
