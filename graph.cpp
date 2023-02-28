#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int m;
    bool cycle;
    bool used[505][505];
    vector<vector<char>> g;
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0, 0, -1, 1};
    void dfs(int i, int j, int prevI = -1, int prevJ = -1)
    {
        used[i][j] = true;
        for (int next = 0; next < 4; next++)
        {
            int x = nextX[next] + i;
            int y = nextY[next] + j;
            if (x == prevI && y == prevJ)
                continue;
            if (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == g[i][j])
            {
                if (used[x][y])
                {
                    cycle = true;
                    return;
                }
                dfs(x, y, i, j);
            }
        }
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        g = grid;
        n = grid.size();
        m = grid[0].size();
        memset(used, false, sizeof(used));
        cycle = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!used[i][j])
                {
                    dfs(i, j);
                }
                if (cycle)
                    return true;
            }
        }
        return false;
    }
};
