#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"
#include "queue"

using namespace std;

class Solution
{
public:
    int maxA(int N)
    {
        int *mat = new int[N + 1]{0};

        for (int i = 1; i <= N; i++)
        {
            mat[i] = mat[i - 1] + 1;

            for (int j = 2; j < i - 1; j++)
            {
                mat[i] = max(mat[i], mat[j] * (i - j - 1));
            }
        }

        return mat[N];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.maxA(7));

    return 0;
}
