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
    inline long hash(vector<int> &vec, unordered_map<long, long> &idx_map)
    {
        long hash_value = 0;
        int hash_bit_offset = 0;

        for (auto &i : vec)
        {
            hash_value |= idx_map[i] << (hash_bit_offset * 8);
            ++hash_bit_offset;
        }

        return hash_value;
    }
    inline bool increase(int target , vector<int> nums,vector<int> &pointer, int n, set<long> &hash_dict, unordered_map<long, long> &idx_map)
    {
        int c = pointer.size() - 1;

        while (c > 0)
        {
            int max = (n - (4 - c - 1));

            if (pointer[c] < max)
            {
                pointer[c]++;

                while (pointer[c] >= max)
                {
                    --c;
                    pointer[c] += 1;
                    int t = c;
                    while (t < 3)
                    {
                        pointer[t + 1] = pointer[t] + 1;
                        ++t;
                    }

                    max = (n - (4 - c - 1));
                }

                auto s = nums[pointer[0]] + nums[pointer[1]] + nums[pointer[2]] + nums[pointer[3]];

                if(target==s){
                    int value = hash(pointer, idx_map);

                    if (hash_dict.find(value) == hash_dict.end())
                    {
                        hash_dict.insert(value);
                        return true;
                    }
                }
            }
        }

        return false;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>();

        vector<vector<int>> ret;
        set<long> hash_dict;
        unordered_map<long, long> idx_map, idx_tmp;
        int nc = nums.size();
        vector<int> vec;
        vec.resize(4);

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nc; i++)
        {
            idx_tmp[nums[i]] = -1;
        }

        for (size_t i = 0; i < nc; i++)
        {
            if (idx_tmp[nums[i]] < 0)
            {
                idx_tmp[nums[i]] = i;
                idx_map[i] = i;
            }
            else
            {
                idx_map[i] = idx_tmp[nums[i]];
            }
        }

        for (size_t i = 0; i < 4; i++)
        {
            vec[i] = i;
        }

        vector<int> tmp;

        while (increase(target,nums, vec, nc, hash_dict, idx_map))
        {
            auto s = nums[vec[0]] + nums[vec[1]] + nums[vec[2]] + nums[vec[3]];

            if (s == target)
            {
                
                tmp.clear();

                for (auto &i : vec)
                {
                    tmp.push_back(nums[i]);
                }

                ret.push_back(tmp);
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // s.fourSum(vector<int>{1, 0, -1, 0, -2, 2, -1, 2, 3, 1, -3, -1, 1, 2, 3, 4, 4}, 1);
    // s.fourSum(vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 4);
    s.fourSum(vector<int>{ -494,-474,-425,-424,-391,-371,-365,-351,-345,-304,-292,-289,-283,-256,-236,-236,-236,-226,-225,-223,-217,-185,-174,-163,-157,-148,-145,-130,-103,-84,-71,-67,-55,-16,-13,-11,1,19,28,28,43,48,49,53,78,79,91,99,115,122,132,154,176,180,185,185,206,207,272,274,316,321,327,327,346,380,386,391,400,404,424,432,440,463,465,466,475,486,492}, -1211);
    // s.fourSum(vector<int>{1, 0, -1, 0, -2, 2}, 0);
    // s.fourSum(vector<int>{1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 4);
    return 0;
}
