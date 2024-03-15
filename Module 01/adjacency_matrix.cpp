#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; // n holo vertices // e holo edges
    cin >> n >> e;

    int mat[n][e];
    memset(mat, 0, sizeof(mat));
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    int a, b;
    cin >> a >> b;
    if (mat[a][b] == 1)
    {
        cout << "Connection ase" << endl;
    }
    else
    {
        cout << "Connection nai" << endl;
    }

    return 0;
}