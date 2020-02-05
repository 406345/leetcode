#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int ret = 0;
        int l= 0,r=0;
        int m = INT_MIN;

        while(l<size && r < size){
            auto t = ret  + nums[r];

            if(t < nums[r]){
                l = r;
                r = l + 1;
                ret = nums[l];
            }else{
                ++r;
                ret = t;
            }


            m = max(m,ret);
        }        

        return r-l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.maxSubArray(vector<int>({-2,1,-3,4,-1,2,1,-5,4})));

    return 0;
}
