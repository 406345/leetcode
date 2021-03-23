#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "set"
#include "ctime"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)\n", tick);                             \
    }

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    { 
        sort(intervals.begin(),intervals.end(), [](auto& v1,auto& v2){
            return v1[0] < v2[0];
        });

        vector<vector<int>> result;

        for (auto &i : intervals)
        {
            if(result.empty()){
                result.push_back(i);
            }else{
                if(i[0] > result.back()[1]){
                    result.push_back(i);
                }
                else{
                    result.back()[1] = max(i[1],result.back()[1]);
                }
            } 
        }

        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    TIME(s.merge(vector<vector<int>>{
        vector<int>{20, 30},
        vector<int>{40, 60},
        vector<int>{0, 99}}));

    vector<vector<int>> test;

    for (int i = 0; i < 10000; i++)
    {
        test.push_back(vector<int>{i,i});
    }

    TIME(s.merge(test));

    return 0;
}
