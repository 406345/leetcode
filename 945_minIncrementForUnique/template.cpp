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

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // if(A.size() == 0) return 0;
        int t = 0;
        int ret = 0;

        sort(A.begin(),A.end());


        for (int i = 1; i < A.size(); i++)
        {
            if( A[i-1] < A[i]){
                continue;
            }
            else {
                ret += 1 - (A[i] - A[i-1]) ;
                A[i] = A[i-1] + 1;
            }
        }
        

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.minIncrementForUnique(vector<int>{3,2,1,2,1,7});
    return 0;
}
