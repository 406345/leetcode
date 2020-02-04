#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"

using namespace std;

class Solution
{
public:
    void work(vector<vector<int>> &ret, vector<int> &arr, set<int> &numset)
    { 
        if( numset.size() == 0){
            ret.push_back(arr);
            return;
        }

        for(auto &n: numset){
            vector<int> rank(arr);
            auto numset_tmp = set<int>(numset);
            numset_tmp.erase(n);
            rank.push_back(n);
            work(ret,rank,numset_tmp);
        };
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        set<int> sets;

        for(auto&n: nums) sets.insert(n);
        vector<vector<int>> ret;
        vector<int> tmp;
        work(ret,tmp , sets);
        

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%", s.permute(vector<int>({1, 2, 3})));

    return 0;
}
