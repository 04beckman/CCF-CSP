#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int main(void)
{
    int n, m;
    cin >> n >> m;
    cout << (1 << (n / 3)) % mod;
    system("pause");
    return 0;
}