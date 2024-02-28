#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {

    //Inputting a graph !!

    // 1. As Adjacency Matrix , make using nXn array n=vertex , huge space complexity but O(1) time to find edges exist and their weight
    ll n , m ;
    ll graph1[n+1][n+1];
    for(ll i=0;i<n;i++){
        ll a , b;
        cin>>a>>b;
        //for weighted just add the weight w instead of 1
        graph1[a][b]=1;
        graph1[b][a]=1;
    }

    //2. Adjacency List , space complexity O(E+V) but loop throught a node to find links O(n)
    vector<ll> graph2[n];
    vector<pair<ll,ll>> graph3[n];
    for(ll i=0;i<n;i++){
        ll a , b;
        cin>>a>>b;
        graph2[a].push_back(b);
        graph2[b].push_back(a);

        //for weighted insert pair
        ll w;
        cin>>w;
        graph3[a].push_back({b,w}); 
        graph3[b].push_back({a,w});
    }
}
