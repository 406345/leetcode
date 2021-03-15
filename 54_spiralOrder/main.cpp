#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    struct Vec
    {
        int x = 0, y = 0;
    };

    vector<Vec> direction;

    Solution()
    {
        direction.push_back({1, 0});
        direction.push_back({0, 1});
        direction.push_back({-1, 0});
        direction.push_back({0, -1});
    };

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        vector<vector<bool>> visited_map;
        Vec dir ;
        Vec tmp;
        Vec ;
        int didx = 0;

        int row = matrix.size();
        int column = matrix[0].size();

        visited_map.resize(row);

        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                visited_map[i].push_back(false);
            }
        }

        bool new_dir = true;

        while (true)
        {
           
            if (tmp.y < 0 || tmp.y >= row || tmp.x < 0 || tmp.x >= column || visited_map[tmp.y][tmp.x] == true){
                didx = (didx +1 ) % 4;

                if( new_dir == false){
                    break;
                }
                new_dir = false;
                tmp = dir;
            }
            else{
                dir = tmp;
                new_dir = true;
                ret.push_back(matrix[dir.y][dir.x]);
                visited_map[dir.y][dir.x] = true;
                
            }

            tmp.x += direction[didx].x;
            tmp.y += direction[didx].y;

        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix;

    matrix.push_back({1, 2, 3});
    matrix.push_back({4, 5, 6});
    matrix.push_back({7, 8, 9});

    s.spiralOrder(matrix);

    return 0;
}
