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
    struct result{
        int sum;
        int pos;
        vector<int> nums;
    };

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        queue<result> q;
        
        for (int i = 0; i < n; i++)
        {
            q.push(result{
                candidates[i],
                i,
                vector<int>{candidates[i]}
            });
        }

        while(!q.empty()){
            auto& t = q.front();
 
            if(t.sum>target){
                q.pop();
                continue;
            }

            if(t.pos>n){
                 q.pop();
                 continue;
            }

            if (t.sum == target)
            {
                ret.push_back(std::move(t.nums));
                q.pop();
                continue;
            }

        
            int k = 0;
            while(true)
            {
                if((t.pos + k)>=n)break;

                auto s = t.sum + candidates[t.pos + k];

                if(s>target){
                    break;
                }

                auto next = result{
                    s,
                    t.pos + k,
                    vector<int>(t.nums)};
                    
                next.nums.push_back(candidates[t.pos + k]);

                if (next.sum == target)
                {
                    ret.push_back(std::move(next.nums));
                }
                else
                {
                    q.push(next);
                }
                ++k;
            }
            
            q.pop();
        }

        sort(ret.begin(),ret.end(),[](auto& x1,auto& x2){
            return x1.size() > x2.size();
        });
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.combinationSum(vector<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},7);
    s.combinationSum(vector<int>{1},8);
    s.combinationSum(vector<int>{2,3,6,7},7);
    return 0;
}
