#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> adj(n);
  for (int i = 0; i < e; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  int q;
  cin >> q;

  while (q--)
  {
    int a, b;
    cin >> a >> b;

    bool direct = (a == b);
    if (!direct)
    {
      for (int child : adj[a])
      {
        if (child == b)
        {
          direct = true;
          break;
        }
      }
    }

    if (direct)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
