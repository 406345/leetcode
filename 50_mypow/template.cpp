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
    inline double mul(double x, long long n) {
        if (n == 0)
            return 1;

        double ret = x;
        double tmp = x;
        auto flag = false; 

        if( (n & 1) == 0){
            ret = 1;
        }

        n = n >> 1;

        while (n>0)
        {
            tmp *= tmp;

            flag = (n & 1) == 1;

            if (flag)
            {
                ret = ret * tmp;
            } 

           
            n = n >> 1;
        }

        return ret;
    }

    double myPow(double x, int n)
    {
        double ret = 1, last = x;

        ret = mul(x, abs(n));

        if (n < 0)
        {
            ret = 1 / ret;
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
     s.myPow(1.00001, 1);
     s.myPow(1.00001, 1);
  s.myPow(1.00001, -214);
    s.myPow(1.00001, 214);
    return 0;
}
