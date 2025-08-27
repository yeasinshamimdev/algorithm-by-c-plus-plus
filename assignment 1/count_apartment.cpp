#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool valid(int i, int j)
{
  return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  q.push(make_pair(si, sj));
  vis[si][sj] = true;

  while (!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    int x = par.first;
    int y = par.second;

    for (int k = 0; k < 4; k++)
    {
      int nx = x + d[k].first;
      int ny = y + d[k].second;
      if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.')
      {
        vis[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> grid[i][j];
    }
  }

  memset(vis, false, sizeof(vis));

  int apartments = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (grid[i][j] == '.' && !vis[i][j])
      {
        apartments++;
        bfs(i, j);
      }
    }
  }

  cout << apartments << "\n";
  return 0;
}
