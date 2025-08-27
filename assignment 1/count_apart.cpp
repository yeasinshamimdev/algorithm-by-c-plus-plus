#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool valid(int i, int j)
{
  return i >= 0 && i < n && j >= 0 && j < m;
}

int room_cnt;

void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  q.push(make_pair(si, sj));
  vis[si][sj] = true;
  room_cnt = 1;

  while (!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    int x = par.first, y = par.second;

    for (int k = 0; k < 4; k++)
    {
      int nx = x + d[k].first;
      int ny = y + d[k].second;
      if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.')
      {
        vis[nx][ny] = true;
        q.push(make_pair(nx, ny));
        room_cnt++;
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  grid.resize(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> grid[i];
  }

  vis.assign(n, vector<bool>(m, false));

  vector<int> sizes;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (grid[i][j] == '.' && !vis[i][j])
      {
        bfs(i, j);
        sizes.push_back(room_cnt);
      }
    }
  }

  if (sizes.empty())
  {
    cout << 0 << "\n";
    return 0;
  }

  sort(sizes.begin(), sizes.end());
  for (size_t i = 0; i < sizes.size(); ++i)
  {
    cout << sizes[i] << (i + 1 == sizes.size() ? '\n' : ' ');
  }
  return 0;
}
