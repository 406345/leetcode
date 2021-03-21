#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "algorithm"

using namespace std;

class Solution
{
public:
    inline bool exist(vector<vector<int>> c, vector<int> t){
        for(auto& v: c){
            bool is_same = true;
            for (size_t i = 0; i < t.size(); i++)
            {
                if( v[i] != t[i]){
                    is_same = false;
                    break;
                }
            }

            if(is_same){
                return true;
            }
        }

        return false;
    };

    int mini_rage(vector<int> &nums,int number,int from,int to){
        int l=from,r=to;
        int p =0;
        while(l<r){
            p = (l+r)>>1;
            if(nums[p] < number){
                l = p+1;
            } 
            else{
                break;
            }
        }

        return p; 
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>();
        vector<vector<int>> ret;
        int nc = nums.size();
        vector<int> vec;
        vec.resize(4);

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nc - 3; i++)
        {
            int sum1 = nums[i];

            if( sum1 > target){
                break;
            }

            int maxi = mini_rage(nums, target - sum1, i + 1, nc);

            for (size_t j = i; j < maxi; j++)
            {
                int sum2 = nums[i];

                if (sum2 > target)
                {
                    break;
                }


            }

            // for (size_t j = i + 1; j < nc - 2; j++)
            // {
            //     long sum1 = nums[i] + nums[j];

            //     if (sum1 > target)
            //     {
            //         return ret;
            //     }
            //     for (size_t k = j + 1; k < nc - 1; k++)
            //     {
            //         long sum2 = nums[i] + nums[j] + + nums[k];

            //         if (sum2 > target)
            //         {
            //             return ret;
            //         }

            //         for (size_t l = k + 1; l < nc; l++)
            //         {
            //             long sum3 = nums[i] + nums[j] + nums[k] + nums[l];
            //             if (sum3 > target)
            //             {
            //                 return ret;
            //             }
            //             else if (sum3 == target)
            //             {
            //                 auto tmp = vector<int>{nums[i], nums[j], nums[k] , nums[l]};
            //                 if(!exist(ret,tmp)){
            //                     ret.push_back(tmp);
            //                 }
            //             }
            //         }
            //     }
            // }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.fourSum(vector<int>{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 4);
    s.fourSum(vector<int>{1, 0, -1, 0, -2, 2}, -1);
    return 0;
}
