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
    struct result
    {
        int sum;
        map<int, int>::iterator pos;
        vector<int> nums;
    };
 
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    { 
        vector<vector<int>> ret;
        map<int, int> sums;
        int n = candidates.size();
        queue<result> q;

        // sort(candidates.begin(), candidates.end());

        for (size_t i = 0; i < n; i++)
        {
            sums[candidates[i]] += 1;
        }

        int pos = 0;
        for (auto kv = sums.begin(); kv != sums.end(); kv++)
        {
            q.push({0,
                    kv,
                    vector<int>{}});
        }

        while (!q.empty())
        {
            auto &t = q.front();

            if (t.sum == target)
            {
                ret.push_back(t.nums);
                q.pop();
                continue;
            }

            if (t.pos == sums.end())
            {
                q.pop();
                continue;
            }
 
            for (int i = 1; i <= (*t.pos).second; i++)
            {
                int s = t.sum + i * (*t.pos).first;

                if (s > target)
                {
                    break;
                }

                vector<int> nums(t.nums);

                for (size_t j = 0; j < i; j++)
                {
                    nums.push_back((*t.pos).first);
                }

                if (s == target)
                {
                    ret.push_back(nums);
                    break;
                }

                auto pp = t.pos;

                for (auto& j = ++pp; ; j++)
                {
                    q.push({
                        s,
                        j,
                        nums,
                    });
                    
                    if(j == sums.end())break;
                }
            }

            q.pop();
        }

        return ret;
    } 
};

int main(int argc, char const *argv[])
{
    Solution s;
    // s.combinationSum2(vector<int>{1, 1, 1, 1, 1, 1, 2, 2, 2, 2}, 8);
    s.combinationSum2(vector<int>{10, 1, 2, 7, 6, 1, 5, 1, 2, 5, 7, 1, 2, 2, 2, 1, 2, 17, 8, 12, 7, 8, 9, 1, 2, 6, 7, 8, 5, 6, 7, 2, 34, 6, 4, 6, 1, 2, 5, 2}, 10);
    s.combinationSum2(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8);
    s.combinationSum2(vector<int>{1}, 8);
    s.combinationSum2(vector<int>{2, 3, 6, 7}, 7);
    return 0;
}
