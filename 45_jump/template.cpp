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

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = -1;
        }

        dp[0] = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                int cur = dp[i] + 1;

                if( (i+j) >= nums.size())
                    break;
                if( dp[i+j] <0 || dp[i+j] > cur){
                    dp[i+j] = cur;
                } 
            }
            
        }
        

        return dp[nums.size()-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s; 
    s.jump(vector<int>{2,3,1,1,4});
    
    return 0;
}
