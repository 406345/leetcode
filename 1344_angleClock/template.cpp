#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "algorithm"
#include "string"
#include "queue"
#include "stack"
#include "ctime"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)", tick);                               \
    }

using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double m_angle = 360. / 60. * minutes;

        double h_angel = 360. / 12. * (hour % 12) + (360/12 * (minutes/60.));

        double ret = abs(h_angel - m_angle);

        return min(360 - ret, ret);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.angleClock(12, 30);
    return 0;
}
