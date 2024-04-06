// this is an example question for MuliSource BFS 
// question Link https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll>> moves = {
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1},
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool valid(ll coordX, ll coordY, ll n, ll m)
{
    return coordX >= 0 && coordX < n && coordY >= 0 && coordY < m;
}

void bfs(vector<pair<ll, ll>> sources, vector<vector<ll>> &levels, vector<vector<ll>> graph, vector<vector<ll>> visited)
{
    queue<pair<ll, ll>> q;
    for (auto i : sources)
    {
        q.push(i);
        visited[i.first][i.second] = 1;
    }
    while (!q.empty())
    {
        ll parX = q.front().first;
        ll parY = q.front().second;
        q.pop();
        for (auto move : moves)
        {
            ll coordX = parX + move.first;
            ll coordY = parY + move.second;
            if (!valid(coordX, coordY, graph.size(), graph[0].size()))
                continue;
            if (visited[coordX][coordY])
                continue;
            levels[coordX][coordY] = levels[parX][parY] + 1;
            visited[coordX][coordY] = 1;
            q.push({coordX, coordY});
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n, vector<ll>(m));
    vector<vector<ll>> levels(n, vector<ll>(m));
    vector<vector<ll>> visited(n, vector<ll>(m));
    ll maxy = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            maxy = max(graph[i][j], maxy);
        }
    }
    vector<pair<ll, ll>> sources;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (graph[i][j] == maxy)
                sources.push_back({i, j});
        }
    }
    bfs(sources, levels, graph, visited);
    maxy = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            // cout<<levels[i][j]<<" ";
            maxy = max(levels[i][j], maxy);
        }
        // cout<<endl;
    }
    cout << maxy << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}