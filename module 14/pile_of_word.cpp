#include <bits/stdc++.h>
using namespace std;

bool isPileOfWord(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;
    int cnt[26] = {0};
    for (char c : a)
        cnt[c - 'a']++;
    for (char c : b)
        cnt[c - 'a']--;
    for (int i = 0; i < 26; ++i)
        if (cnt[i] != 0)
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (isPileOfWord(s1, s2) ? "YES" : "NO") << "\n";
    }
    return 0;
}
