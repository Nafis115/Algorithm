#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visi[100];

int  dfs(int s, int &coun)
{
    coun++;
    visi[s] = true;
    for (int child : adj[s])
        if (visi[child] == false)
        {
            dfs(child,coun);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin >> s;
    memset(visi, false, sizeof(visi));
    int count = 0;
    dfs(s, count);
    cout << count << endl;

    return 0;
}