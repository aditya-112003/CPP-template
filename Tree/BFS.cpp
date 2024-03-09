#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;

int visited[N];
int level[N];
vector<ll> graph[N];



void bfs (int source){
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        for(int child : graph[currentVertex]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1; 
                level[child] = level[currentVertex] + 1; 
            }
        }
    }
}

int main(){
    ll n ;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll a , b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
}