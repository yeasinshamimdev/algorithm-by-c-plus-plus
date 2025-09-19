#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    long long tetran[n + 1];
    tetran[0] = 0;
    tetran[1] = 1;
    tetran[2] = 1;
    tetran[3] = 2;

    for (int i = 4; i <= n; i++)
    {
        tetran[i] = tetran[i - 1] + tetran[i - 2] + tetran[i - 3] + tetran[i - 4];
    }

    cout << tetran[n] << endl;
    return 0;
}
