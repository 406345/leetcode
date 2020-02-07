#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void print(long long **matrix, int n, int m)
    {
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        printf("======================\n");
    }
    int minPathSum(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        long long **box = new long long *[n + 2]{0};

        for (int i = 0; i < n + 2 ; i++)
        {
            box[i] = new long long[m+2]{INT_MAX};
        }

        for (int i = 0; i < n+2; i++)
        {
            for (int j = 0; j < m+2; j++)
            {
                box[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < m ; i++)
        {
            box[0][i] = INT_MAX;
        }


        box[0][0] = 0;
        box[1][0] = 0;
        box[0][1] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                auto left = box[i][j - 1];
                auto up = box[i - 1][j];
                box[i][j] = obstacleGrid[i-1][j-1] + min(left, up);
                print(box, n, m);
            }
        }

        return box[n][m];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.minPathSum(
                       vector<vector<int>>({
                           vector<int>({1, 3, 1}),
                           vector<int>({1, 5, 1}),
                           vector<int>({4, 2, 1}),
                       })));
    // printf("%d\n", s.uniquePathsWithObstacles(
    //                    vector<vector<int>>({
    //                        vector<int>({1}),
    //                    })));
    //printf("%d\n",s.uniquePaths(3,2));
    // printf("%d\n",s.uniquePaths(7,3));
    // printf("%d\n",s.uniquePaths(3,3));

    return 0;
}
