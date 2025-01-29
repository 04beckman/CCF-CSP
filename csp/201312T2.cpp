#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int main(void)
{
    string temp;
    cin >> temp;
    int number = 0;
    number += temp[0] - '0';
    number += (temp[2] - '0') * 2;
    number += (temp[3] - '0') * 3;
    number += (temp[4] - '0') * 4;
    number += (temp[6] - '0') * 5;
    number += (temp[7] - '0') * 6;
    number += (temp[8] - '0') * 7;
    number += (temp[9] - '0') * 8;
    number += (temp[10] - '0') * 9;
    int k = number % 11;
    char ch;
    if (k == 10)
        ch = 'X';
    else
        ch = '0' + k;
    if (ch == temp[12])
        cout << "Right" << endl;
    else
    {
        temp[12] = ch;
        cout << temp;
    }
    system("pause");
    return 0;
}
/*
0-670-82162-4
*/