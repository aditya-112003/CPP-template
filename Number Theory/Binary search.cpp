#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll x;
    cin>>x;
    ll f=n-1,b=0;
    ll mid;
    while (f-b>1){
        mid=(f+b)/2;
        if(v[mid]<x) b=mid+1;
        else f=mid;
    }
    if(v[f]==x) cout<<f<<endl;
    else if (v[b]==x) cout<<b<<endl;
    else cout<<"not found"<<endl;
    return 0;
}

// Upper Bound or Lower Bound using Binary Search 

void lowerbound(vector<ll> &v,ll element){
    ll b=0,f=v.size(),mid=0;
    while(f-b>1){
        mid=(f+b)/2;
        if(v[mid]<element) b=mid+1;
        else f=mid;
    }
    if(v[b]>=element) cout<<v[b]<<endl;
    else if (v[f]>=element) cout<<v[f]<<endl;
    else {
        cout<<-1<<endl;
    }return ;
}

void upperbound(vector<ll> &v,ll element){
    ll b=0,f=v.size(),mid=0;
    while(f-b>1){
        mid=(f+b)/2;
        if(v[mid]<=element) b=mid+1;
        else f=mid;
    }
    if(v[b]>element) cout<<v[b]<<endl;
    else if (v[f]>element) cout<<v[f]<<endl;
    else {
        cout<<-1<<endl;
    }return ;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll x;
    cin>>x;
    upperbound(v,x);
    return 0;
}
