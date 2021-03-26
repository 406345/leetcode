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
#include "assert.h"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)", tick);                               \
    }

using namespace std;

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int s1 = min(x1,x2);
        int s2 = max(x1,x2);

        vector<int> buf ;
        buf.resize(length);

        for (int i = s1; i < s2+1; i++)
        {
            int pos = y * w + i;
            int bpos = pos / 32;
            int bbpos = pos % 32;

            buf[bpos] |= 1 << (31-bbpos);
        }

        return buf;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.drawLine(6,64,55,104,2);
    return 0;
}
