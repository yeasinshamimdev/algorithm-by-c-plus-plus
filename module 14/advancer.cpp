#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int val[1005], weightArr[1005];
long long dp[1005][1005];

long long knapsack(int i, int cap)
{
    if (i < 0 || cap <= 0)
        return 0;

    if (dp[i][cap] != -1)
        return dp[i][cap];

    if (weightArr[i] <= cap)
    {
        long long take = knapsack(i - 1, cap - weightArr[i]) + val[i];
        long long skip = knapsack(i - 1, cap);
        return dp[i][cap] = max(take, skip);
    }
    else
    {
        return dp[i][cap] = knapsack(i - 1, cap);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;

        for (int i = 0; i < n; i++)
            cin >> weightArr[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n; i++)
            for (int w = 0; w <= W; w++)
                dp[i][w] = -1;

        cout << knapsack(n - 1, W) << "\n";
    }
    return 0;
}
