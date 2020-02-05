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
    void print(int **matrix, int r, int c)
    {
        for (size_t i = 1; i <= c; i++)
        {
            for (size_t j = 1; j <= r; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        printf("======================\n");
    }
    int uniquePaths(int m, int n)
    {
        long long **box = new long long *[n + 2];

        for (int i = 0; i < n + 2; i++)
        {
            box[i] = new long long[m + 2]{0};
        }

        box[1][1] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                auto left = box[i][j - 1];
                auto up = box[i - 1][j];
                box[i][j] = max(box[i][j], left + up);
                //print(box,m,n);
            }
        }

        return box[n][m];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    //printf("%d\n",s.uniquePaths(3,2));
    printf("%d\n", s.uniquePaths(0, 0));
    printf("%d\n", s.uniquePaths(1, 1));
    // printf("%d\n",s.uniquePaths(7,3));
    // printf("%d\n",s.uniquePaths(3,3));

    return 0;
}
