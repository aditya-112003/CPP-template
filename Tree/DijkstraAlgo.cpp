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
        q.erase(q.begin());
        if (visited[par.second])
            continue;
        visited[par.second] = true;
        for (auto child : g[par.second])
        {
            if (dist[par.second] + par.first >= dist[child.second])
                continue;
            dist[child.second] = dist[par.second] + par.first;
            q.insert({dist[child.second], child.second});
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