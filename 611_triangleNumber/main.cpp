#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int size = nums.size();
        int count = 0;

        for (size_t i = 0; i < size; i++)
        {
            auto l = nums[i];

            for (size_t j = i + 1; j < size; j++)
            {
                auto v1 = nums[j];
                for (size_t k = j + 1; k < size; k++)
                {
                    auto sum = v1 + nums[k];

                    if (l < sum)
                    {
                        ++count;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.triangleNumber(vector<int>({2, 3, 2, 4}));

    return 0;
}
