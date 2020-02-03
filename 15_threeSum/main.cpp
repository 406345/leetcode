#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        int size = nums.size();

        if (size <  3)
            return ret;

        sort(nums.begin(), nums.end());
        size = nums.size();
        int l = 0, r = 0, tmp = 0, v= 0;
        
        for (int i = 0; i < size ;)
        {
            l = i + 1;
            r = size - 1;

            while (l < r)
            {
                auto sum = nums[i] + nums[l] + nums[r];

                if (sum < 0)
                {
                    v = nums[l];
                    while (l<size && v == nums[l])++l;
                }
                else if (sum > 0)
                {
                    v = nums[r];
                    while (r>=0 && v == nums[r])--r;
                }
                else
                {
                    ret.push_back({nums[i], nums[l], nums[r]});
                     v = nums[l];
                    while (l<size && v == nums[l])++l;
                    v = nums[r];
                    while (r>=0 && v == nums[r])--r;
                }
            }

            int  v = nums[i];
            while(i<size && v == nums[i]) ++i;
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.threeSum(vector<int>({-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6})));
    printf("%d\n", s.threeSum(vector<int>({0, 0, 0})));
    printf("%d\n", s.threeSum(vector<int>({-4, -1, -1, 0, 1, 2})));
    printf("%d\n", s.threeSum(vector<int>({-1, 0, 1, 2, -1, -4})));
    printf("%d\n", s.threeSum(vector<int>({})));

    return 0;
}
