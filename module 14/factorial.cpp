#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    int mul = factorial(n - 1);
    return n * mul;
}

int main()
{
    int ans = factorial(4);
    cout << ans << endl;

    return 0;
}
