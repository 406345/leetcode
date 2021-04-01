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
    void inline swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    };

    void wiggleSort(vector<int> &nums)
    {

        vector<int> diff;
        int c = nums.size();

        for (size_t i = 1; i < c; i++)
        {
            if (i % 2 == 0)
            {
                if (nums[i] < nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
            else
            {
                if (nums[i] > nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> i;
    i = {1, 2, 3, 4, 5, 6};
    s.wiggleSort(i);

    i = {1, 6, 4, 2, 3, 4, 6};
    s.wiggleSort(i);
    return 0;
}
