#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;

  vector<vector<int>> adj(n);
  for (int i = 0; i < e; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i)
  {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    reverse(adj[i].begin(), adj[i].end());
  }

  int q;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    if (adj[x].empty())
    {
      cout << -1 << '\n';
    }
    else
    {
      for (int v : adj[x])
        cout << v << ' ';
      cout << '\n';
    }
  }
  return 0;
}
