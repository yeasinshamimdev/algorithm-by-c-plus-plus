#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<char>> vis;
int si, sj, di, dj;
bool found_path = false;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool inside(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int r, int c)
{
    if (found_path)
        return;
    if (r == di && c == dj)
    {
        found_path = true;
        return;
    }
    vis[r][c] = 1;

    for (int k = 0; k < 4; k++)
    {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (inside(nr, nc) && !vis[nr][nc] && grid[nr][nc] == '.')
        {
            dfs(nr, nc);
            if (found_path)
                return;
        }
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    cin >> si >> sj;
    cin >> di >> dj;

    if (si < 0 || si >= n || sj < 0 || sj >= m ||
        di < 0 || di >= n || dj < 0 || dj >= m ||
        grid[si][sj] == '-' || grid[di][dj] == '-')
    {
        cout << "NO\n";
        return 0;
    }

    vis.assign(n, vector<char>(m, 0));

    dfs(si, sj);

    cout << (found_path ? "YES\n" : "NO\n");
    return 0;
}
