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

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        long long d1 = dividend;
        long long d2 = divisor;

        if (d1 < 0)
            d1 = ~(d1 - 1);

        if (d2 < 0)
            d2 = ~(d2 - 1);

        bool s1 = dividend > 0;
        bool s2 = divisor > 0;

        long long count = 0;

        long long d3 = d2;
        long long times = 1;
        while (d1 >= d2)
        {
            d1 -= d3; 
            d3 = d3 << 1; 
            count += times;
            times += times;
        }

        d1 = d1+(d3>>1);
        count = count - (times>>1);

        while(d1>=d2){
            d1 -= d2;
            count += 1;
        }

  
        if (s1 != s2) 
        {
            count = ~count + 1;
        }

        if(count<-2147483648LL){
            return 2147483647;
        }

        if( count > 2147483647LL){
            return 2147483647;
        }

        return count;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // s.divide(11234, 1);

    int ret =0;
    ret = s.divide(98, 3);
    ret = s.divide(99, 3);
    ret = s.divide(-2147483648, 2);
    ret = s.divide(-2147483648, 3);
    ret = s.divide(-2147483647, -1);
    return 0;
}
