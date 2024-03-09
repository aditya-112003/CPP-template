#include <bits/stdc++.h>
using namespace std;

int visited[8][8];
int level[8][8];

int coordX(string source)
{
    return source[0] - 'a';
}

int coordY(string source)
{
    return source[1] - '1';
}

vector<pair<int, int>> movements = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
};

bool isValid(pair<int, int> move)
{
    return move.first <= 7 && move.first >= 0 && move.second >= 0 && move.second <= 7;
}

void bfs(int sourceX, int sourceY)
{
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    visited[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;
    while (!q.empty())
    {
        int parX = q.front().first;
        int parY = q.front().second;
        q.pop();
        for (auto movement : movements)
        {
            int childX = parX + movement.first;
            int childY = parY + movement.second;
            if (!isValid({childX, childY}))
                continue;
            if (visited[childX][childY])
                continue;
            q.push({childX, childY});
            level[childX][childY] = level[parX][parY] + 1;
            visited[childX][childY] = 1;
        }
    }
}

void reset ()
{
    for(int i = 0 ; i < 8 ; i ++){
        for( int j = 0 ; j < 8 ; j ++){
            level[i][j]=0;
            visited[i][j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int sourceX = coordX(a);
        int sourceY = coordY(a);
        int destX = coordX(b);
        int destY = coordY(b);
        bfs(sourceX, sourceY);
        cout << level[destX][destY] << '\n';
        reset();
    }
    return 0;
}