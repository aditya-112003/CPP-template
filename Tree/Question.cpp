#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    ll par_A = find(a);
    ll par_B = find(b);
    if (par_A == par_B)
        return;
    if (size[par_A] < size[par_B])
        swap(par_A, par_B);
    parent[par_B] = par_A;
    size[par_A] += size[par_B];
}

void solve()
{
    ll n;
    cin >> n;
    ll k = n;
    vector<pair<ll, ll>> node;
    vector<pair<ll, pair<ll, ll>>> edges;
    while (k--)
    {
        ll x, y;
        cin >> x >> y;
        node.push_back({x, y});
    }
    vector<ll> powerStation(n + 1);
    vector<ll> wire(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> powerStation[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> wire[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
            {
                edges.push_back({powerStation[i], {i, 0}});
                continue;
            }
            ll dist = (wire[i] + wire[j]) * (abs(node[i - 1].first - node[j - 1].first) + abs(node[i - 1].second - node[j - 1].second));
            edges.push_back({dist, {i, j}});
        }
    }
    cout << endl;
    sort(edges.begin(), edges.end());
    for (ll i = 0; i <= n; i++)
    {
        make(i);
    }
    vector<ll> ans_station;
    vector<pair<ll, ll>> ans_wire;
    ll totatCost = 0;
    for (auto &edge : edges)
    {
        // cout << edge.first << ":" << edge.second.first << ":" << edge.second.second << " ";
        ll wt = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        totatCost += wt;
        if (v == 0)
        {
            ans_station.push_back(u);
            continue;
        }
        ans_wire.push_back({u, v});
    }
    cout << endl;
    cout << totatCost << '\n';
    cout << ans_station.size() << '\n';
    for (auto i : ans_station)
    {
        cout << i << " ";
    }
    cout << '\n';
    cout << ans_wire.size() << '\n';
    for (auto i : ans_wire)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}