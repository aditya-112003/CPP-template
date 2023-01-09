#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<ll,ll> p,pair<ll,ll> q){
    if(p.first!=q.first){
        return p.first<q.first;
    }return p.second>q.second;
    
}

int main(){
    
    //sorting and comparator functions

    ll n;
    cin>>n;
    ll arr[n];
    vector<ll> v;
    sort(arr,arr+n);
    sort(arr+2,arr+n);
    sort(v.begin(),v.end());

    vector<pair<ll,ll>> v2(n);
    sort(v2.begin(),v2.end(),cmp);

    //upper and lower bound on sorted 
    //lower bound the address of value itself or next greatest element 
    //upper bound indicates the next greatest element

    auto its=upper_bound(arr,arr+n,9);// O(log(n)) nd O(n)for unsorted
    auto its=lower_bound(arr+4,arr+n,9);//return pointer or address
    auto it=upper_bound(v.begin(),v.end(),6);

    //for maps and set

    set<ll> s;
    auto it=upper_bound(v.begin(),v.end(),6); // O(n)
    auto it=s.upper_bound(6); //O(log(n))
    //same for maps
}
