// https://codeforces.com/problemset/problem/295/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 510;
const int INF = 1e9 + 10;

ll dist[N][N];

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    vector<ll> v(n), ans;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    reverse(v.begin(), v.end());

    for (ll k = 0; k < n; k++)
    {
        ll node = v[k];
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][node] + dist[node][j]);
            }
        }

        ll sum = 0;
        for (ll i = 0; i <= k; i++)
        {
            for (ll j = 0; j <= k; j++)
            {
                sum += dist[v[i]][v[j]];
            }
        }
        // cout << sum << " ";
        ans.push_back(sum);
    }
    cout << endl;
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
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