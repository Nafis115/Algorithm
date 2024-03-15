#include<bits/stdc++.h>
using namespace std;
int main(){

  int n,e;
  cin>>n>>e;
  vector<int>mat[n];
  while (n--)
  {
   int a,b;
   cin>>a>>b;
   mat[a].push_back(b);
   mat[b].push_back(a);
  }
  int a;
  cin>>a;
for (int i = 0; i < mat[a].size(); i++)
{
    cout<<mat[a][i]<<endl;
}










     return 0;
}