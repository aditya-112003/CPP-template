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

/// DSU time complexity is O(alpha(n)) here alpa is inverse Ackermann function , and this time complexity is called amortized complexity .

int main()
{
    // example question find connected components after connect operation
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        ll u, v;
        cin >> u >> v;
        Union(u, v);
    }
    ll ct = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (find(i) == i)
            ct++;
    }
    cout << ct;
}