#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    unordered_map<string, int> quanxian;
    unordered_map<string, unordered_map<string, int>> jiaose;
    unordered_map<string, unordered_map<string, int>> yonghu;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int k = s.find(':');
        if (k == -1)
        {
            quanxian[s] = 1;
        }
        else
        {
            int dengji = s[s.size() - 1] - '0' + 2;
            s.pop_back();
            s.pop_back();
            quanxian[s] = dengji;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            int k = s.find(':');
            if (k == -1)
            {
                jiaose[name][s] = 1;
            }
            else
            {
                int dengji = s[s.size() - 1] - '0' + 2;
                s.pop_back();
                s.pop_back();
                jiaose[name][s] = max(dengji, jiaose[name][s]);
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            for (auto &x : jiaose[s])
            {
                yonghu[name][x.first] = max(x.second, yonghu[name][x.first]);
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name;
        string chaxu;
        cin >> name >> chaxu;
        int dengji = 0;
        int k = chaxu.find(':');
        if (k != -1)
        {
            dengji = chaxu[chaxu.size() - 1] - '0' + 2;
            chaxu.pop_back();
            chaxu.pop_back();
        }
        if (yonghu[name].empty() || quanxian[chaxu] == 0)
        {
            cout << "false" << endl;
            continue;
        }
        if (k == -1)
        {
            if (yonghu[name][chaxu] >= 2)
                cout << yonghu[name][chaxu] - 2 << endl;
            else if (yonghu[name][chaxu] == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else
        {
            if (yonghu[name][chaxu] >= dengji)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    system("pause");
    return 0;
}