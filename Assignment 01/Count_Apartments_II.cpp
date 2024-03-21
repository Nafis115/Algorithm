#include <bits/stdc++.h>
using namespace std;
int n, m;
int c = 0;
vector<int> v;
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

int dfs(int si, int sj)
{

    c++;
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
    return c;
}

int main()
{
    int find=0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
            {
                if (vis[i][j] == false)
                {
                    c = 0;
                   int r= dfs(i, j);
                    v.push_back(r);
                    find=1;
                }
            }
        }
    }
    sort(v.begin(),v.end());
    if(find==1){
          for (int val : v)
    {
        cout << val <<" ";
    }
    }else{
        cout<<"0";
    }
  

    return 0;
}