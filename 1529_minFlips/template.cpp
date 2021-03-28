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
 
    int minFlips(string target) {  
        int ret = 0;
        int size = target.length();
        char last =  '0';
        int start = 0;
 
        for (size_t i = start; i < size; i++)
        { 
            if( target[i] == last ){
                continue;
            }
            else{
                last = target[i];
                ++ret;
            }
        }
        

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.minFlips("11000");
    s.minFlips("0000000");
    s.minFlips("10111");
    return 0;
}
