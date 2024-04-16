#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;

vector<pair<ll, ll>> g[N];

void dijkstra(ll source)
{
    vector<bool> visited(N, false);
    vector<ll> dist(N, 1e9 + 10);

    set<pair<ll, ll>> q; // priority queue can be used here
    q.insert({0, source});
    dist[source] = 0;

    while (q.size() > 0)
    {
        auto par = *q.begin();
        ll node = par.second;
        ll node_dist = par.first;
        q.erase(q.begin());
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto child : g[node])
        {
            ll wt = child.second;
            ll child_node = child.first;
            if (dist[node] + wt < dist[child_node])
            {
                dist[child_node] = dist[node] + wt;
                q.insert({dist[child_node], child_node});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, wt; // wt connect from x to y
        cin >> x >> y >> wt;
        g[x].push_back({wt, y}); // since edge is directed only one push back .
    }
    dijkstra(1);
}