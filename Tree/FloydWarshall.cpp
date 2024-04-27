#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510;
const ll INF = 1e9 + 10;

ll dist[N][N];

// handle -ve weights but not -ve weight cycles
// O(n^3) number of vertices
int main()
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF) // this condition is mainly because of -ve weights
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}