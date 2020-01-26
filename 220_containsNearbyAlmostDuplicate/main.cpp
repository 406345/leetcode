#include "stdio.h"
#include "vector"
#include "set"
#include "algorithm"
#include "unordered_map"

using namespace std;

struct cmp
{
    bool operator()(const int &x, const int &y) const
    {
        return x > y;
    }
};

class Solution
{
private:
    inline long long  abs(long long  x)
    {
        long long  y;
        y = x >> 63;
        return (x ^ y) - y;
    };

    inline long long  id(long long x, long long  k)
    {
        return x<0? -((-x/k)+1)  : (x/ k)+1;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if( k == 0) return false;

        unordered_map<long long , long long > map;
        int size = nums.size();
        int step = this->abs(t)+1;

        for (int i = 0; i < size; i++)
        {
            auto key = this->id(nums[i], step);

            if (map.find(key) != map.end() && this->abs(map[key] - nums[i]) <= t)
            {
                return true;
            }

            if (map.find(key - 1) != map.end() && this->abs(map[key - 1] - nums[i]) <= t)
            {
                return true;
            }

            if (map.find(key + 1) != map.end() && this->abs(map[key + 1] - nums[i]) <= t)
            {
                return true;
            }

            map[key] = (nums[i]);

            if (i >= k)
            {
                auto v  = this->id(nums[i - k],step);
                map.erase(map.find(v));
            }
        }

        return false;
    }
};
int main(int argc, char const *argv[])
{ 
    Solution s;
    s.containsNearbyAlmostDuplicate(vector<int>({2147483647, -2147483647}), 1, 2147483647);
    s.containsNearbyAlmostDuplicate(vector<int>({5,-5,5,-5,5,15}), 6,6);
    s.containsNearbyAlmostDuplicate(vector<int>({-5,5,5,5,5,15}), 6,6);
    s.containsNearbyAlmostDuplicate(vector<int>({1, 5, 9, 1, 5, 9}), 2, 3);
    s.containsNearbyAlmostDuplicate(vector<int>({1, 1}), 0, 0);
    s.containsNearbyAlmostDuplicate(vector<int>({7, 1, 3}), 2, 3);
    s.containsNearbyAlmostDuplicate(vector<int>({2, 1}), 1, 1);
    s.containsNearbyAlmostDuplicate(vector<int>({2, 2}), 3, 0);
    s.containsNearbyAlmostDuplicate(vector<int>({1, 1}), 1, 1);
    s.containsNearbyAlmostDuplicate(vector<int>({1, 1}), 1, 0);
    s.containsNearbyAlmostDuplicate(vector<int>({1, 1}), 0, 1);

    return 0;
}
