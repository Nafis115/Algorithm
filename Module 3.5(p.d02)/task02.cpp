#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];

bool visi[100];

void  dfs(int s,int &c)
{
    c++;
    visi[s] = true;
    for (int child : adj[s])
        if (visi[child] == false)
        {
            dfs(child,c);
        }
      
}

int main()
{
    int n, e;

    cin >> n >> e;

    while (e--)
    {
        int a, b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visi, false, sizeof(visi));
  
    
    for (int i = 0; i < n; i++)
    {
        if (visi[i] == false)
        {
            int count = 0;
           dfs(i,count);
            cout << count << endl;
        }
    }



    return 0;
}