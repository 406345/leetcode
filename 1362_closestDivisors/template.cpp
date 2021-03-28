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
    vector<int> divide(int& min_delta, int num){
        int mid = sqrt(num);
        int delta = 0; 
        int x1=0,x2= 0;
        for (int i = 1; i <= mid; i++)
        {
            if(num % i == 0){
                delta = abs(num/i - i);
                if(min_delta>delta){
                    x1 = i;
                    x2 = num/i;
                    min_delta = delta;
                }
            }
        }
        return {x1,x2};
    }
    vector<int> closestDivisors(int num) {
        int d1 = 0x7FFFFFFF;
        int d2 = 0x7FFFFFFF;

        auto r1 = divide(d1,num+1);
        auto r2 = divide(d2,num+2);

        if(d1<d2){
            return r1;
        }

        return r2;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    TIME(s.closestDivisors(1000000000));
    return 0;
}
