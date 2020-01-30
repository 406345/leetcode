#include "stdio.h"
#include "vector"
#include "unordered_map"
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &n, int lower, int upper)
    {
        vector<string> ret;
        vector<long long> nums;


        for(auto& k : n){
            nums.push_back((long long)k);
        }

        if (nums.size() == 0 || nums[nums.size() - 1] < upper)
        {
            nums.push_back((long long)upper+1);
        }

        if(nums.size() == 0 || nums[0] > lower){
            nums.insert(nums.begin(),(long long)lower-1);
        }

        int count = nums.size();

        for (int i = 0; i < count - 1; i++)
        {
            auto delta = (long long)nums[i + 1] - (long long)nums[i];
            if (delta == 1)
            {
                continue;
            }
            else if (delta == 2)
            {
                ret.push_back(to_string(nums[i] + 1));
            }
            else if (delta > 2)
            {
                ret.push_back(to_string(nums[i] + 1) + "->" + to_string(nums[i + 1] - 1));
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.findMissingRanges(vector<int>({2147483647}) ,-2147483647, 2147483647);
    s.findMissingRanges(vector<int>({1}) ,0, 1);
    s.findMissingRanges(vector<int>({0, 1, 3, 50, 75}) ,0, 99);

    return 0;
}
