#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];

void dfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    bool paisi = false;
    vis[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        if (par == des)
        {
            cout << level<< endl;
            bool paisi = true;
        }
        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src, des;
    cin >> src>> des;
    memset(vis, false, sizeof(vis));

    dfs(src, des);

    return 0;
}