#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std; 

class Solution
{
public: 
    int findMinArrowShots(vector<vector<int>> &points)
    { 
        if(points.size() == 0) return 0;

       
        sort(points.begin(),points.end(), 
            [](const vector<int> & p1, const vector<int> & p2 ){
                return p1[1]<p2[1];
            });

        int left= points[0][0];
        int right = points[0][1];
        int ret = 1;

        for(auto &p : points){
            if(right < p[0]){
                right = p[1];
                ++ret;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.findMinArrowShots(vector<vector<int>>({
        vector<int>({12, 16}),
        vector<int>({2, 8}),
        vector<int>({1, 6}),
        vector<int>({7, 12}),
        vector<int>({66, 99})
    }));

    return 0;
}
