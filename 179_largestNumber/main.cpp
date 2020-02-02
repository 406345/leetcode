#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "string"
#include "algorithm"

using namespace std;

bool compare(int i1, int i2)
{
    if( i1 == i2 ){return true;}
    
    string a = to_string(i1);
    string b = to_string(i2);

    auto num = a.length() + b.length();
    auto la = a.length(), lb = b.length();

    for (size_t i = 0; i < num; i++)
    {
        char ac = 0, bc = 0;

        if (i >= la)
        {
            ac = b[(i - la)];
        }
        else
        {
            ac = a[i];
        }

        if (i >= lb)
        {
            bc = a[i - lb];
        }
        else
        {
            bc = b[i];
        }

        if (ac != bc)
        {
            return ac > bc;
        }
    }

    return true; 
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        
        stable_sort(nums.begin(), nums.end(), compare);

        string ret = "";

        if (nums[0] == 0)
        {
            return "0";
        }

        for (auto& t : nums)
        {
            ret = ret + to_string(t);
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    printf("%s\n", s.largestNumber(vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})));
    printf("%s\n", s.largestNumber(vector<int>({3, 30, 34})));
    printf("%s\n", s.largestNumber(vector<int>({128, 12})));
    printf("%s\n", s.largestNumber(vector<int>({999999998, 999999997, 999999999})));
    printf("%s\n", s.largestNumber(vector<int>({3, 30, 34, 5, 9})));
    printf("%s\n", s.largestNumber(vector<int>({10, 1})));
    printf("%s\n", s.largestNumber(vector<int>({3, 30})));
    printf("%s\n", s.largestNumber(vector<int>({20, 1})));

    return 0;
}
