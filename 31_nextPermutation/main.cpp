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
    inline int bs(int p, int v, vector<int> &nums)
    {
        int l = p;
        int r = nums.size() - 1;
        int s = l;
        while (l <= r)
        {
            s = (l + r) >> 1;

            if (nums[s] > v)
            {
                r = s - 1;
            }
            else
            {
                l = s + 1;
            }
        }

        for (size_t i = s; i < nums.size(); i++)
        {
            if (nums[i] > v)
            {
                return i;
            }
        }

        return s;
    }
    inline void swap(int &n1, int &n2)
    {
        int t = n1;
        n1 = n2;
        n2 = t;
    }
    void nextPermutation(vector<int> &nums)
    {
        int s = nums.size() - 1;
        int l = nums.size() - 1;

        while (s > 0)
        {
            if (nums[s - 1] < nums[s])
            {
                break;
            }
            --s;
        }

        if (s == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        sort(nums.begin() + s, nums.end());

        int p = bs(s, nums[s - 1], nums);

        swap(nums[p], nums[s - 1]);

        sort(nums.begin() + s, nums.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.nextPermutation(vector<int>{1, 5, 9, 7, 6});
    s.nextPermutation(vector<int>{2, 2, 7, 5, 4, 3, 2, 2, 1});
    s.nextPermutation(vector<int>{0, 3, 6, 9, 12, 11, 10, 9, 8, 4, 2, 5, 3, 1});
    s.nextPermutation(vector<int>{3, 4, 9, 5, 3, 1, 1, 1, 1, 1, 4, 5, 6, 7, 11, 2, 1});
    s.nextPermutation(vector<int>{1, 2, 1});
    s.nextPermutation(vector<int>{3, 4, 9, 5, 3, 1, 1, 1, 1, 1, 4});
    s.nextPermutation(vector<int>{3, 4, 9, 5, 4, 3, 1, 1});
    return 0;
}
