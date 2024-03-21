#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{

    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            if (mat[ci][cj] != '#')
            {
                dfs(ci, cj);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ai = -1, aj = -1;
    int bi = -1, bj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (mat[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    dfs(ai, aj);

    if (vis[bi][bj] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}