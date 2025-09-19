#include <bits/stdc++.h>
using namespace std;

bool canReach(long long n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;

    unordered_set<long long> seen;
    vector<long long> st = {1};

    while (!st.empty())
    {
        long long x = st.back();
        st.pop_back();

        if (x == n)
            return true;
        if (x > n)
            continue;
        if (!seen.insert(x).second)
            continue;

        if (x <= n / 2)
            st.push_back(x * 2);
        if (x <= n - 3)
            st.push_back(x + 3);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << (canReach(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}
