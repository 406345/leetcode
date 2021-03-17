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
#include "functional"

using namespace std;

class Solution
{
public:
    struct Point
    {
        int x, y;
    };

    void swip(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    };

    inline Point transform(Point &t, int n)
    {
        int hn = n >> 1;
        return Point{
            t.x + hn,
            hn - t.y};
    }

    inline void printMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        printf("=====================\n");

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                printf("%d\t", matrix[i][j]);
            }

            printf("\n");
        }
    }
   void rotate(vector<vector<int>> &matrix)
    {
        // n = 4
        // 1,0 -> 3,1 -> 2,3 -> 0,2
        //
        int n = matrix.size();
        int d = n >> 1;
        for (int j = 0; j < d; j++)
        {
            for (int i = j; i < n-1 - j; i++)
            {
                Point p = {i, j};
                int tmp =  matrix[p.y][p.x];
                for (int k = 0; k < 4; k++)
                {
                    swip(p.x, p.y);
                    p.x = n - 1 - p.x;
                    swip(matrix[p.y][p.x], tmp);
                }

                printMatrix(matrix);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> matrix;

    matrix.push_back(vector<int>{5, 1, 9, 11});
    matrix.push_back(vector<int>{2, 4, 8, 10});
    matrix.push_back(vector<int>{13, 3, 6, 7});
    matrix.push_back(vector<int>{15, 14, 12, 16});
    // matrix.push_back(vector<int>{});
    s.rotate(matrix);
    return 0;
}
