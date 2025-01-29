#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct character
{
    int hp;
    int at;
};
struct node
{
    vector<character> members;
} man[2];
int main(void)
{
    int n;
    cin >> n;
    int i = 0;

    man[0].members.resize(1);
    man[1].members.resize(1);
    man[0].members[0].hp = 30;
    man[1].members[0].hp = 30;
    man[0].members[0].at = 0;
    man[1].members[0].at = 0;
    while (n)
    {
        while (n)
        {
            string mingling;
            cin >> mingling;
            n--;
            if (mingling == "end")
                break;
            else if (mingling == "summon")
            {
                int pos, H, A;
                cin >> pos >> A >> H;
                if (man[i % 2].members.size() <= pos)
                {
                    character tmp;
                    tmp.hp = H;
                    tmp.at = A;
                    man[i % 2].members.push_back(tmp);
                }
                else
                {

                    man[i % 2].members.resize(man[i % 2].members.size() + 1);
                    for (int j = man[i % 2].members.size(); j > pos; --j)
                    {
                        man[i % 2].members[j] = man[i % 2].members[j - 1];
                    }
                    man[i % 2].members[pos].hp = H;
                    man[i % 2].members[pos].at = A;
                }
            }
            else
            {
                int p1, p2;
                cin >> p1 >> p2;
                character &c1 = man[i % 2].members[p1];
                character &c2 = man[(i + 1) % 2].members[p2];
                c1.hp -= c2.at;
                c2.hp -= c1.at;
                if (c1.hp <= 0)
                {
                    if (p1 == 0)
                        break;
                    man[i % 2].members.erase(man[i % 2].members.begin() + p1);
                }
                if (c2.hp <= 0)
                {
                    if (p2 == 0)
                        break;
                    man[(i + 1) % 2].members.erase(man[(i + 1) % 2].members.begin() + p2);
                }
            }
        }
        i++;
    }
    if (man[0].members[0].hp <= 0)
        cout << -1 << endl;
    else if (man[1].members[0].hp <= 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    cout << man[0].members[0].hp << endl;
    cout << man[0].members.size() - 1 << " ";
    for (int i = 1; i <= man[0].members.size() - 1; ++i)
    {
        cout << man[0].members[i].hp << " ";
    }
    cout << endl;
    cout << man[1].members[0].hp << endl;
    cout << man[1].members.size() - 1 << " ";
    for (int i = 1; i <= man[1].members.size() - 1; ++i)
    {
        cout << man[1].members[i].hp << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}