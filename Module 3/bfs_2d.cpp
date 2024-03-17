#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[20][20];
int d1[20][20];
vector<pair<int, int>> d = {{0, 1}, {0 ,- 1}, {-1, 0}, {1, 0}};

bool visi[20][20];
bool valid(int i, int j)
{
    if (i < 0 || n <= i || j < 0 || m <= j)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    d1[si][sj] = 0;
    visi[si][sj] = true;
    while (!q.empty())
    {
        
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && visi[ci][cj] == false)
            {
                q.push({ci, cj});
                visi[ci][cj] = true;
                d1[ci][cj] = d1[a][b] + 1;
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
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    memset(visi, false, sizeof(visi));
    memset(d1,-1,sizeof(d1));
    bfs(si, sj);
   cout<<d1[2][3]<<endl;
    return 0;
}