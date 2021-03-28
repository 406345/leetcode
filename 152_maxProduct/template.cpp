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
public:
    int maxProduct(vector<int> &nums)
    {
        int count = nums.size();
        vector<int> n_max(nums), n_min(nums);


        for (size_t i = 1; i < count; i++)
        {
            n_max[i] = max(n_max[i - 1] * nums[i], max(n_min[i - 1] * nums[i], nums[i]));
            n_min[i] = min(n_min[i - 1] * nums[i], min(n_max[i-1]*nums[i],nums[i]));
        }


        return *max_element(n_max.begin(), n_max.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret = 0;
    ret = s.maxProduct(vector<int>{-1,-2,-3,-4});
    ret = s.maxProduct(vector<int>{-10, -1, 1, 2, 3, 4, 5, -10});
    ret = s.maxProduct(vector<int>{-10, -1, 1, 2, 3, 4, 5, -10});
    ret = s.maxProduct(vector<int>{-1, -2, 0, -1, -2, -2, -5});
    ret = s.maxProduct(vector<int>{-2, 1});

    s.maxProduct(vector<int>{-1, -2, -3});
    return 0;
}
