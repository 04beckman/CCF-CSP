
#include <iostream>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int a, b, xK, yK, xQ, yQ;
        std::cin >> a >> b >> xK >> yK >> xQ >> yQ;

        int count = 0;
        for (int dx = -1; dx <= 1; dx += 2)
        {
            for (int dy = -1; dy <= 1; dy += 2)
            {
                int x = xK + a * dx;
                int y = yK + b * dy;

                if (std::abs(x - xQ) == a && std::abs(y - yQ) == b)
                {
                    count++;
                }
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}