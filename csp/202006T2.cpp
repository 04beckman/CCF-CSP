#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'A')
            a.emplace_back(x, y);
        else
            b.emplace_back(x, y);
    }
    for (int i = 0; i < m; ++i)
    {
        long long x1, x2, x3, j;
        cin >> x3 >> x1 >> x2;
        long long last = 0;
        long long at = 0, bt = 0;
        for (j = 0; j < a.size(); ++j)
        {
            long long now = x1 * a[j].first + x2 * a[j].second + x3;
            if (now * last < 0)
                break;
            last = now;
            at = now;
        }
        if (j != a.size())
        {
            cout << "No" << endl;
            continue;
        }
        last = 0;
        for (j = 0; j < b.size(); ++j)
        {
            long long now = x1 * b[j].first + x2 * b[j].second + x3;
            if (now * last < 0)
                break;
            last = now;
            bt = now;
        }
        if (j != b.size())
        {
            cout << "No" << endl;
            continue;
        }
        if (at * bt < 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    map<char, vector<int>> g;
    vector<vector<int>> s(n + 1);
    g.insert(pair<char, vector<int>>('a', s[0]));
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
*/