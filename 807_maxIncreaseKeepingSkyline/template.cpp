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
#include "ctime"
#include "assert.h"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)", tick);                               \
    }

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        if( grid.size() == 0)
            return 0;

        int ret = 0;
        int row_count = grid.size();
        int col_count = grid[0].size();
        int* front = new int[row_count];
        int* left = new int[col_count];

        memset(front, 0, row_count * sizeof(int));
        memset(left, 0, col_count * sizeof(int));

        int row_num = 0;

        for (int i = 0; i < row_count; i++)
        {
            for (int j = 0; j < col_count; j++)
            {
                front[j] = max(front[j], grid[i][j]);
            }
        }

        for (int j = 0; j < col_count; j++)
        {
            for (int i = 0; i < row_count; i++)
            {
                left[i] = max(left[i], grid[i][j]);
            }
        }


        for (int i = 0; i < row_count; i++)
        {
            for (int j = 0; j < col_count; j++)
            {
                 int v = grid[i][j];

                 int max_front = front[j];
                 int max_left = left[i];

                 int increase = min(max_front,max_left) - v;

                 if( increase > 0){
                     ret += increase;
                 }


            }
        }



        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> input;

    input.push_back({3,0,8,4});
    input.push_back({2,4,5,7});
    input.push_back({9,2,6,3});
    input.push_back({0,3,1,0});

    assert(s.maxIncreaseKeepingSkyline(input) == 35); 

    return 0;
}
