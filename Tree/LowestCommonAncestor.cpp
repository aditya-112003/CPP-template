#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;

// Store parent in array to find path of nodes , then make a path array for given nodes , compare those 2 find the last common node in their array to find the common parent . 

vector<ll> graph[N];
int par[N]; 

void dfs(ll vertex , ll parent = -1){
    par[N]=parent;
    for(ll child : graph[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
    }
}

vector<int> pathArrayMaker (int v) {
    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[N];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main () {
    ll n , m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a , b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll x , y ;
    vector<int> path_x = pathArrayMaker(x);
    vector<int> path_y = pathArrayMaker(y);
    ll LCA = 0;
    for(ll i=0;i<min(path_x.size(),path_y.size());i++){
        if(path_x[i]==path_y[i]){
            LCA = path_x[i];
        }else break;
    }
}