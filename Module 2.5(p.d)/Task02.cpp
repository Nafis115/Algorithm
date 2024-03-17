#include <bits/stdc++.h>
using namespace std;
bool visi[1005];
vector<int> v[1005];
int level[1005];
void dfs(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visi[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (visi[child] == false)
            {
                q.push(child);
                visi[child] = true;
                level[child] = level[par] + 1;
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
    memset(visi, false, sizeof(visi));
    memset(level, -1, sizeof(level));

    dfs(0);
    int l;
    cin >> l;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == l)
        {
            cout << i << endl;
        }
    }

    return 0;
}