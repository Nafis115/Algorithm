#include <bits/stdc++.h>
using namespace std;
int paren[1005];
vector<int> v[1005];
bool vis[1005];

void dfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                paren[child] = par;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
        memset(paren, -1, sizeof(paren));
        dfs(src);

        int x = des;
        vector<int> st;
        while (x != -1)
        {
            st.push_back(x);
            x = paren[x];
        }

        cout << st.size() - 1 << endl;
        st.clear();
    }
    return 0;
}