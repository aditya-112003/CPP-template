#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;

vector<ll> graph[N];
int depth[N],height[N]; 
int subtree_sum[N];

void dfs(ll vertex , ll parent = 0){
    for(ll child : graph[vertex]){
        if(child==parent) continue;
        depth[child]=depth[parent]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex] , height[child]+1);
    }
}

// example question computing sum of a subtree 
void dfs2(ll vertex , int parent = 0 ) {
    subtree_sum[vertex]+=vertex;
    for(ll child : graph[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
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

    dfs(1);
}