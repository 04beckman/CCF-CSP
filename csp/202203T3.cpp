#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <cstring>
using namespace std;
int n;
vector<vector<long>> g(2510, vector<long>(510, 0));
set<int> k(string &temp)
{
    set<int> ans;
    int texing = 0;
    int i = 0;
    while ('0' <= temp[i] && temp[i] <= '9')
    {
        texing = texing * 10 + (temp[i] - '0');
        ++i;
    }
    char op = temp[i];
    ++i;
    int zhi = 0;
    for (; i < temp.size(); ++i)
    {
        zhi = zhi * 10 + (temp[i] - '0');
    }
    if (op == ':')
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[j][texing] == zhi)
                ans.insert(g[j][0]);
        }
    }
    else
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[j][texing] != 0 && g[j][texing] != zhi)
                ans.insert(g[j][0]);
        }
    }
    return ans;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int dn;
        int num;
        cin >> dn >> num;
        g[i][0] = dn;
        while (num--)
        {
            long a, b;
            cin >> a >> b;
            g[i][a] = b;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        string temp;
        cin >> temp;
        if (temp[0] == '&' || temp[0] == '|')
        {
            if (temp[0] == '|')
            {
                vector<int> zuoluohao;
                vector<int> youkuohao;
                for (int i = 0; i < temp.size(); ++i)
                {
                    if (temp[i] == '(')
                        zuoluohao.push_back(i);
                    else if (temp[i] == ')')
                        youkuohao.push_back(i);
                }
                set<int> all;
                for (int j = 0; j < zuoluohao.size(); ++j)
                {
                    string z = temp.substr(zuoluohao[j] + 1, youkuohao[j] - zuoluohao[j] - 1);
                    auto tmp = k(z);
                    for (auto iter = tmp.begin(); iter != tmp.end(); ++iter)
                        all.insert(*iter);
                }
                for (auto iter = all.begin(); iter != all.end(); ++iter)
                    cout << *iter << " ";
                cout << endl;
            }
            else
            {
                vector<int> zuoluohao;
                vector<int> youkuohao;
                for (int i = 0; i < temp.size(); ++i)
                {
                    if (temp[i] == '(')
                        zuoluohao.push_back(i);
                    else if (temp[i] == ')')
                        youkuohao.push_back(i);
                }
                int cnt = zuoluohao.size();
                unordered_map<int, int> all;
                set<int> ans;
                for (int j = 0; j < zuoluohao.size(); ++j)
                {
                    string z = temp.substr(zuoluohao[j] + 1, youkuohao[j] - zuoluohao[j] - 1);
                    auto tmp = k(z);
                    for (auto iter = tmp.begin(); iter != tmp.end(); ++iter)
                    {
                        all[*iter]++;
                        if (all[*iter] == cnt)
                            ans.insert(*iter);
                    }
                }
                for (auto iter = ans.begin(); iter != ans.end(); ++iter)
                    cout << *iter << " ";
                cout << endl;
            }
        }
        else
        {
            auto tmp = k(temp);
            for (auto iter = tmp.begin(); iter != tmp.end(); ++iter)
                cout << *iter << " ";
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
