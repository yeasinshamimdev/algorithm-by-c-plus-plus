#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1005];

int fibonacci(int n)
{
    if (n < 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int ans = fibonacci(5);
    cout << ans << endl;

    return 0;
}
