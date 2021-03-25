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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int big_num = (tomatoSlices - 2*cheeseSlices) ;

        int small_num = 4 * cheeseSlices - tomatoSlices;

        if( big_num >= 0 && small_num >= 0 && big_num % 2 == 0 && small_num % 2 == 0){
            return {big_num/2,small_num/2};
        }

        return {};
    }   
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.numOfBurgers(1,17);
    s.numOfBurgers(1,17);
    s.numOfBurgers(0,0);
    s.numOfBurgers(4,17);
    s.numOfBurgers(16,7);
    s.numOfBurgers(17,4);
    return 0;
}
