#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;

bool visited[N];
vector<ll> graph[N];

void dfs (ll vertex){
    visited[vertex] = true;
    for(ll child : graph[vertex]){
        if(visited[child]) continue;
        dfs(child);
    }
}

//for Cycle detection 
bool dfsCycle(ll vertex , ll parent){
    visited[vertex]=true;
    bool isLoopExists = false;
    for(ll child : graph[vertex]){
        if(visited[child] && child==parent) continue;
        if(visited[child]) return true;
        isLoopExists |= dfsCycle(child , vertex);
    }
    return isLoopExists;
}

// O(V+E) time complexity for DFS

int main () {
    ll n , m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a , b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //for Cycle Detection
    bool isLoopExists = false;
    for(ll i=1;i<=n;i++){ // for every vertex 
        if(visited[i]) continue;
        if(dfsCycle(i , 0)){
            isLoopExists = true;
            break;
        }
    }
}