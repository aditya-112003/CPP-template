#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;

bool visited[N] ;
vector<ll> graph[N];

void dfs (ll vertex){
    visited[vertex] = true;
    for(ll child : graph[vertex]){
        if(visited[child]) continue;
        dfs(child);
    }
}

void solve(){
    ll n , m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a , b;
        cin>>a>>b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll comp = 0 ;
    for(ll i=1;i<=n;i++){
        if(visited[i]) continue;
        dfs(i);
        comp++;
    }
    cout<<comp<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}