#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int leveld[MAXN][MAXN];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < m);
}

inline bool walkable(char c)
{
  return c == '.' || c == 'A' || c == 'B';
}

void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  q.push({si, sj});
  vis[si][sj] = true;
  leveld[si][sj] = 0;

  while (!q.empty())
  {
    auto par = q.front();
    q.pop();
    int par_i = par.first, par_j = par.second;

    for (int k = 0; k < 4; k++)
    {
      int ci = par_i + d[k].first;
      int cj = par_j + d[k].second;
      if (valid(ci, cj) && !vis[ci][cj] && walkable(grid[ci][cj]))
      {
        vis[ci][cj] = true;
        leveld[ci][cj] = leveld[par_i][par_j] + 1;
        q.push({ci, cj});
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  pair<int, int> s = {-1, -1}, t = {-1, -1};

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        s = {i, j};
      if (grid[i][j] == 'B')
        t = {i, j};
    }

  if (s.first == -1 || t.first == -1)
  {
    cout << "NO\n";
    return 0;
  }

  memset(vis, false, sizeof(vis));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      leveld[i][j] = -1;

  bfs(s.first, s.second);

  cout << (vis[t.first][t.second] ? "YES\n" : "NO\n");
  return 0;
}
