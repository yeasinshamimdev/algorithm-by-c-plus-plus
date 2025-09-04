#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({10, 1});
    pq.push({5, 2});

    cout << pq.top().first << " " << pq.top().second << endl;
    return 0;
}
