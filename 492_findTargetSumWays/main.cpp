#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "queue"
#include "math.h"

using namespace std;

class Solution
{
private:
    int count = 0;

public:
    void find(vector<int> &nums, int S, int curSum, int pos)
    {
        if (pos == nums.size())
        {
            if( curSum == S )
                ++count;
            return;
        }

        find(nums, S, curSum + nums[pos], pos+1);
        find(nums, S, curSum - nums[pos], pos+1);
    }
    int findTargetSumWays(vector<int> &nums, int S)
    {
        this->find(nums, S, 0, 0);
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.findTargetSumWays(vector<int>({42, 16, 31, 11, 36, 19, 9, 3, 25, 0, 27, 29, 35, 29, 45, 15, 35, 42, 35, 23}), 39));
    printf("%d\n", s.findTargetSumWays(vector<int>({1, 1, 1}), 3));
    printf("%d\n", s.findTargetSumWays(vector<int>({1, 1, 1, 1, 1, 1}), 3));

    return 0;
}
