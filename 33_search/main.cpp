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
    inline int findStartPoint(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int m = 0;
        while (l < r)
        {
            m = (l + r) >> 1;

            if( m == l || m == r){
                if( nums[l] > nums[r]){
                    return r;
                }
                else{
                    return l;
                }
            }

            if( nums[m] < nums[l]){
                r = m;
            }
            else if( nums[m] > nums[r]){
                l = m;
            }
            else if( nums[l] < nums[r]){
                return l;
            }
        }

        return m;
    };
    inline int bs(vector<int> &nums, int target, int offset){
        int l=0;
        int r =  nums.size() - 1;
        int ret = -1;
        int cnt = nums.size();

        while( l <= r){
            int m = (l+r)>>1;

            if( nums[(m+offset) % cnt] > target ){
                r = m-1;
            }
            else if( nums[(m+offset) % cnt] < target){
                l = m+1;
            }
            else {
                return (m+offset)%cnt;
            }
        }

        return ret;
    };
    int search(vector<int> &nums, int target)
    {
        int ret = 0;
        int s = this->findStartPoint(nums);
        ret = this->bs(nums,target,s);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.search(vector<int>{11,12,13,14,15,1,2,5,6,8,9}, 0);
    s.search(vector<int>{1,2,5,6,8,9,10,12}, 10);
    s.search(vector<int>{1}, 1);
    s.search(vector<int>{5, 6, 8, 9,10, 2, 3}, 6);
    s.search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0);
    return 0;
}
