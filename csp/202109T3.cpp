#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
struct shenjing
{
    double v;
    double u;
    double a;
    double b;
    double c;
    double d;
    int count;
    unordered_map<int, double> I;
};
static unsigned long next1 = 1;
/* RAND_MAX assumed to be 32767 */
int myrand(void)
{
    next1 = next1 * 1103515245 + 12345;
    return ((unsigned)(next1 / 65536) % 32768);
}
int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int N, S, P, T;
    cin >> N >> S >> P >> T;
    double deltat;
    cin >> deltat;
    vector<shenjing> shenjingyuans(N);
    vector<int> maichong(P); // r值
    unordered_map<int, vector<pair<int, pair<double, int>>>> uivpp;
    int count = 0;
    while (count < N)
    {
        int RN;
        double v1, u1, a1, b1, c1, d1;
        cin >> RN >> v1 >> u1 >> a1 >> b1 >> c1 >> d1;
        for (int i = 0; i < RN; ++i)
        {
            shenjingyuans[count + i].a = a1;
            shenjingyuans[count + i].b = b1;
            shenjingyuans[count + i].c = c1;
            shenjingyuans[count + i].d = d1;
            shenjingyuans[count + i].v = v1;
            shenjingyuans[count + i].u = u1;
            shenjingyuans[count + i].count = 0;
        }
        count += RN;
    }
    for (int i = 0; i < P; ++i)
        cin >> maichong[i];
    for (int i = 0; i < S; ++i)
    {
        int s, t, D;
        double w;
        cin >> s >> t >> w >> D;
        uivpp[s].emplace_back(make_pair(t, make_pair(w, D)));
    }
    for (int time = 1; time < T; ++time)
    {
        for (int i = 0; i < P; ++i)
        {
            int temp = myrand();
            if (temp < maichong[i])
            {
                for (int j = 0; j < uivpp[i + N].size(); ++j)
                {
                    shenjingyuans[uivpp[i + N][j].first].I[time + uivpp[i + N][j].second.second] += uivpp[i + N][j].second.first;
                }
            }
        }
    }
    for (int time = 1; time <= T; ++time)
    {
        for (int i = 0; i < shenjingyuans.size(); ++i)
        {
            double temp_v = shenjingyuans[i].v;
            double temp_u = shenjingyuans[i].u;
            shenjingyuans[i].v = temp_v + deltat * (0.04 * temp_v * temp_v + temp_v * 5.0 + 140.0 - temp_u) + shenjingyuans[i].I[time];
            shenjingyuans[i].u = temp_u + deltat * shenjingyuans[i].a * (shenjingyuans[i].b * temp_v - temp_u);
            if (shenjingyuans[i].v >= 30)
            {
                shenjingyuans[i].count++;
                shenjingyuans[i].v = shenjingyuans[i].c;
                shenjingyuans[i].u += shenjingyuans[i].d;
                for (int j = 0; j < uivpp[i].size(); ++j)
                {
                    shenjingyuans[uivpp[i][j].first].I[time + uivpp[i][j].second.second] += uivpp[i][j].second.first;
                }
            }
        }
    }
    int max_cnt = 0, min_cnt = INT_MAX;
    double max_v = INT_MIN, min_v = INT_MAX;
    for (int i = 0; i < N; ++i)
    {
        if (shenjingyuans[i].count > max_cnt)
            max_cnt = shenjingyuans[i].count;
        if (shenjingyuans[i].count < min_cnt)
            min_cnt = shenjingyuans[i].count;
        if (shenjingyuans[i].v > max_v)
            max_v = shenjingyuans[i].v;
        if (shenjingyuans[i].v < min_v)
            min_v = shenjingyuans[i].v;
    }
    printf("%.3lf %.3lf\n", min_v, max_v);
    printf("%d %d", min_cnt, max_cnt);
    return 0;
}