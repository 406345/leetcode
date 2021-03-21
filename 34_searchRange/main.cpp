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
    inline int bs_none_eq(vector<int> &nums, int target, int start, int end, int next)
    {
        int l = start;
        int r = end;
        int ret = -1;
        int m = -1;

        while (l <= r && l>=0 && r>=0)
        {
            m = (l + r) >> 1;

            if (nums[(m)] > target)
            {
                r = m - 1;
            }
            else if (nums[(m)] < target)
            {
                l = m + 1;
            }
            else
            {
                if (next > 0)
                {
                    l = m + next;
                    ret = m;
                }
                else
                {
                    r = m + next;
                    ret = m;
                }
            }
        }

        return ret;
    };

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if(nums.size() == 0)return vector<int>{-1,-1};
        int left = -1;
        int right = -1;
        int lt = nums.size() - 1;

        left = bs_none_eq(nums, target, 0, lt, -1);
        right = bs_none_eq(nums, target, left, lt, 1);
 
        return vector<int>{left, right};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
     vector<int> ret;
    ret = s.searchRange(vector<int>{}, 8);
    ret = s.searchRange(vector<int>{1}, 8);
    ret = s.searchRange(vector<int>{5, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9}, 8);
    ret = s.searchRange(vector<int>{1}, 8);
    ret = s.searchRange(vector<int>{8, 8, 8, 8, 8, 8, 8}, 8);
    ret = s.searchRange(vector<int>{8, 8, 8, 8, 8, 8, 8}, 1);
    ret = s.searchRange(vector<int>{5, 7, 7, 8, 8, 8, 8, 8, 8, 9}, 8);
    return 0;
}
