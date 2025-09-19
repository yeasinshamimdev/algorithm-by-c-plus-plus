#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int fibonacci(int n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(9);

    return 0;
}
