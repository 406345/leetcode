#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ret = 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> rotlist;

        while(true){
            bool existRotOrange = false;
            bool existNormalOrange = false;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if(grid[i][j] == 2){
                        existRotOrange = true;

                        auto upper = (i-1) < 0?-1:i-1;
                        auto left = (j-1)<0?-1:j-1;
                        auto right = (j+1)>=c?-1:j+1;
                        auto down = (i+1)>=r?-1:i+1;

                        if(upper!=-1 && grid[upper][j] == 1)
                            rotlist.push_back(vector<int>({upper,j}));
                        
                        if(down!=-1 && grid[down][j] == 1)
                            rotlist.push_back(vector<int>({down,j}));

                        if(left!=-1 && grid[i][left] == 1)
                            rotlist.push_back(vector<int>({i,left}));
                        
                        if(right!=-1 && grid[i][right] == 1)
                            rotlist.push_back(vector<int>({i,right}));
                    }
                    else if( grid[i][j] == 1){
                        existNormalOrange = true;
                    }
                }
            }

            if( existNormalOrange && rotlist.size() == 0 ) return -1;
            if( !existNormalOrange && rotlist.size() == 0 )return ret;

            for(auto& l : rotlist){
                grid[l[0]][l[1]] = 2;
            }

            rotlist.clear();
            ++ret;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.orangesRotting(vector<vector<int>>({
        vector<int>({2,1,1}),
        vector<int>({0,1,1}),
        vector<int>({1,0,1}),
    })));

    return 0;
}
