#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int N = 1e5 + 10;

    int minFinder(int source, vector<pair<int, int>> graph[], int n)
    {
        vector<bool> visited(N, false);
        vector<int> dist(N, 1e9 + 10);

        set<pair<int, int>> q;
        q.insert({0, source});
        dist[source] = 0;

        while (q.size() > 0)
        {
            auto par = *q.begin();
            q.erase(q.begin());
            if (visited[par.second])
                continue;
            visited[par.second] = true;
            for (auto child : graph[par.second])
            {
                if (dist[par.second] + par.first >= dist[child.second])
                    continue;
                dist[child.second] = dist[par.second] + par.first;
                q.insert({dist[child.second], child.second});
            }
        }
        int maxy = -1;
        for (auto i : dist)
        {
            maxy = max(i, maxy);
        }
        return maxy;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> graph[n];
        int m = times.size();
        for (int i = 0; i < m; i++)
        {
            graph[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        cout<< minFinder(k, graph, n) <<'\n';
    }
};