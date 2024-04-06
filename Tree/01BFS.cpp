// Question Link https://www.codechef.com/KCR22018/problems/REVERSE
// This is an example of concept of 0 1 BFS

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 9;

int visited[N];
int level[N];
vector<pair<ll, ll>> graph[N];

void bfs(int source)
{
    deque<int> q;
    q.push_back(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop_front();
        for (auto child : graph[currentVertex])
        {
            if (visited[child.first])
                continue;
            visited[child.first] = 1;
            if (child.second == 0)
            {
                q.push_front(child.first);
                level[child.first] = level[currentVertex];
            }
            else
            {
                q.push_back(child.first);
                level[child.first] = level[currentVertex] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 1});
    }
    bfs(1);
    cout << level[n];
}