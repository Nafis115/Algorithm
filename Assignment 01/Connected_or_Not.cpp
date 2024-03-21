#include <bits/stdc++.h>
using namespace std;

vector<int> par[1005];

int main()
{

    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        par[a].push_back(b);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int identify = 0;
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            identify = 1;
        }
        else
        {
            for (int child : par[a])
            {
                if (child == b)
                {
                    identify = 1;
                   
                }
            }
          
        }
          if (identify == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
    }

    return 0;
}