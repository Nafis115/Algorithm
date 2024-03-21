#include <bits/stdc++.h>
using namespace std;

vector<int> par[1005];
bool vis[1005];

int main()
{

    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        par[a].push_back(b);
        par[b].push_back(a);
    }
    vector<int> v1;
    int q;
    cin >> q;

    while (q--)
    {
        int count = 0;
        int a;
        cin >> a;

        for (int child : par[a])
        {

            v1.push_back(child);
            count = 1;
        }

        if (count == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(v1.begin(), v1.end(), greater<int>());
            for (int val : v1)
            {
                cout << val << " ";
            }
            v1.clear();
            cout << endl;
        }
    }

    return 0;
}