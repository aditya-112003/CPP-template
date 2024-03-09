#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;

// O(n) approach dfs on any tree and find the node with highest depth , then just put dfs on that node to find the depth of highest node , the depth for this will be the answer .

vector<ll> graph[N];
int depth[N]; 

void dfs(ll vertex , ll parent = 0){
    for(ll child : graph[vertex]){
        if(child==parent) continue;
        depth[child]=depth[parent]+1;
        dfs(child,vertex);
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
    int maxDepth = 0 ;
    int node = 0;
    for(int i=1;i<=n;i++){
        if(depth[i]>=maxDepth){ 
            node = i; // find the node with maximum depth this will be one of the ends of diameter.
        } 
        depth[i]=0;
    }
    dfs(node);
    maxDepth = 0 ;
    for(int i=1;i<=n;i++){
        maxDepth = max(maxDepth , depth[i]); // this shall be the diameter of the tree.
    }
}