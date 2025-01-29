#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> nums(n, 0);
    vector<int> im(m + 1, 0);
    im[0] = n;
    for (int i = 0; i < q; ++i)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (; l <= r; ++l)
            {
                im[nums[l]]--;
                nums[l] = x;
                im[x]++;
            }
        }
        else if (c == 2)
        {
            int x, w;
            cin >> x >> w;
            im[w] += im[x];
            im[x] = 0;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == x)
                    nums[j] = w;
            }
        }
        else if (c == 3)
        {
            int x, y;
            cin >> x >> y;
            swap(im[x], im[y]);
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == x)
                    nums[j] = y;
                else if (nums[j] == y)
                    nums[j] = x;
            }
        }
        else if (c == 4)
        {
            int w;
            cin >> w;
            cout << im[w] << endl;
        }
        else
        {
            auto temp = max_element(im.begin() + 1, im.end());
            if (*temp == 0)
                cout << 0 << endl;
            else
                cout << temp - im.begin() << endl;
        }
    }
    system("pause");
    return 0;
}