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
    vector<int> to_vector(int num){
         vector<int> n1;

        while(num>0){
            n1.push_back(num%10);
            num /= 10;
        }
        reverse(n1.begin(),n1.end());
        return n1;
    }
    void replace_min(vector<int> &num, int max_or_min)
    {
        int c = num.size();
        int yid = 0;
        int y = num[yid];

        if (num[0] > 1)
        {
            y = num[0];
            max_or_min = 1;
        }
        else
        {
            y = -1;
            yid = 0;
            max_or_min = 0;
            while (yid < c )
            {
                int t = num[yid];
                if(t != num[0] && t != max_or_min){
                    y = num[yid];
                    break;
                }

                ++yid;
                
            } 
        }

        for (size_t i = 0; i < c; i++)
        {
            if (num[i] == y)
            {
                num[i] = max_or_min;
            }
        }
    }
    void replace_max(vector<int> &num, int max_or_min)
    {
        int c = num.size();
        int tid = 0;
        int take = num[tid];

        while(tid < c && take == max_or_min){
            take = num[++tid];
        }

        for (size_t i = 0; i < c; i++)
        {
            if (num[i] == take)
            {
                num[i] = max_or_min;
            }
        }

    }
    int maxDiff(int num) {
        if( num < 10) return 8;

        auto n1 = to_vector(num);
        auto n2 = to_vector(num);
 
        int c = n1.size();
        int tmp = n1[0];
        int max_or_min = 9;

        replace_max(n1, 9);
        replace_min(n2, 0);
                
        int i1 = 0,i2 = 0;

        int factor = 1;

        for (int i = c-1; i >=0 ; i--)
        {
            i1 += factor * n1[i];
            i2 += factor * n2[i];
            factor *=10;
        }

        return i1-i2;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    assert(809 == s.maxDiff(109));
    assert(802 == s.maxDiff(102));
    assert(888 == s.maxDiff(111));
    assert(820000 == s.maxDiff(123456));
    assert(808 == s.maxDiff(101));
    assert(8700 == s.maxDiff(9288));
    assert(8 == s.maxDiff(5));
    assert(820000 == s.maxDiff(123456));
    assert(88 == s.maxDiff(11));
    return 0;
}
