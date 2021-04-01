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

class Solution
{
private:

public:
    int minSteps(string s, string t)
    {
        int ret = 0;
        int s_map[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            s_map[s[i] - 'a'] += 1;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s_map[t[i]-'a'] > 0)
            {
                s_map[t[i]-'a'] -= 1;
            }
            else
            {
                ret+=1;
            }
        }
 
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.minSteps(
        "fffffriend",
        "ffffrfiend"
        );
    s.minSteps("leetcode", "practice");
    return 0;
}
