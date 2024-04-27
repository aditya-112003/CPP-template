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

// simple logic , sort edges by weight (lowest first) just add the edges to tree which don't make a loop , DSU will help finding loop edges.
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<pair<ll, pair<ll, ll>>> edges;
    for (ll i = 0; i < n; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (ll i = 0; i < n; i++)
    {
        make(i);
    }

    ll totatCost = 0; // sum of weight of all edges of MST
    for (auto &edge : edges)
    {
        ll wt = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        totatCost += wt;
    }
}