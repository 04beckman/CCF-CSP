#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
struct op
{
    string name;
    vector<int> r;
};
// 拓扑排序判断有没有环 然后直接按题目干就完事了
int Q, M, N;
int main(void)
{
    cin >> Q;
    while (Q--)
    {
        // M表示input个数
        // N表示output个数
        cin >> M >> N;
        vector<op> output(N + 1);
        unordered_map<int, vector<int>> g;
        vector<int> indegree(N + M + 1);
        for (int i = 1; i <= N; ++i)
        {
            string na;
            int n;
            cin >> na >> n;
            output[i].name = na;
            indegree[i + M] = n;
            // 建图
            while (n--)
            {
                string from;
                cin >> from;
                if (from[0] == 'I')
                {
                    int number = 0;
                    for (int j = 1; j < from.size(); ++j)
                        number = number * 10 + (from[j] - '0');
                    g[number].push_back(i + M);
                }
                else
                {
                    int number = 0;
                    for (int j = 1; j < from.size(); ++j)
                        number = number * 10 + (from[j] - '0');
                    g[number + M].push_back(i + M);
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= M; ++i)
        {
            for (auto &x : g[i])
                indegree[x]--;
        }
        vector<int> shunxu;
        for (int i = M + 1; i <= M + N; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                shunxu.push_back(i);
            }
        }
        // 我已经忘记这个shunxu数组是用来干嘛的了....
        int flag = 0;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            for (auto &x : g[temp])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                    shunxu.push_back(x);
                }
                else if (indegree[x] < 0)
                {
                    flag = 1;
                }
            }
        }
        // 此时可以直接判环 但是还需要把其他输入给处理一下
        int S;
        cin >> S;
        vector<vector<int>> temp(2 * S);
        for (int i = 0; i < 2 * S; ++i)
        {
            if (i < S)
            {
                for (int j = 0; j < M; ++j)
                {
                    int n;
                    cin >> n;
                    temp[i].push_back(n);
                }
            }
            else
            {
                int n;
                cin >> n;
                for (int j = 0; j < n; ++j)
                {
                    int z;
                    cin >> z;
                    temp[i].push_back(z);
                }
            }
        }
        if (shunxu.size() != N || flag == 1)
        {
            cout << "LOOP" << endl;
            continue;
        }
    }
}