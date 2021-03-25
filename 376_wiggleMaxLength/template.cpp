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

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int ret = 1;
        vector<long long> deltas;
        int nums_count = nums.size();

        for (size_t i = 1; i < nums_count; i++)
        {
            deltas.push_back(nums[i] - nums[i-1]);
        }

        int detla_count = deltas.size();
        int increase_counter = 1;
        int last_idx = -1;
        for (size_t i = 0;  i < detla_count; i++)
        {
            if(deltas[i] == 0) continue;
            if(last_idx < 0){
                last_idx = i;
                ret = 2;
                continue;
            }
            else if( (deltas[i] * deltas[last_idx]) < 0ll){
                last_idx = i;
                ++ret;
            } 
        }

        return ret;
        
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    assert(s.wiggleMaxLength(vector<int>{1,5,4,2,4,2,4,2}) == 7);
    assert(s.wiggleMaxLength(vector<int>{1,2,3,4,5,6,7,8,9}) == 2);
    assert(s.wiggleMaxLength(vector<int>{2,2,1,1,1,1,1,1,1,2,1,1,1,1}) == 4);
    assert(s.wiggleMaxLength(vector<int>{1,1,1,1,1,1,1}) == 1);
    assert(s.wiggleMaxLength(vector<int>{1,7,4,9,2,5}) == 6);
    assert(s.wiggleMaxLength(vector<int>{1,17,5,10,13,15,10,5,16,8}) == 7);
    assert(s.wiggleMaxLength(vector<int>{1}) == 1);
    assert(s.wiggleMaxLength(vector<int>{}) == 0);
    return 0;
}
