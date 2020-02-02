#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "map"
using namespace std;

class Solution
{
public:
    map<int, int> mat;
    int count(vector<int> &A, int pos, int delta)
    {
        int size = A.size();
        if (pos >= size)
            return 0;
        
        int max = 0;
        for (int i = pos + 1; i < size; i++)
        {
            if ((A[pos] - A[i]) == delta)
            {
                int c = count(A, i, delta);
                if (c >= 0)
                {
                    if ((max) < (c + 1))
                    {
                        max = c + 1;
                    }
                }
            }
        }

        //mat[pos] = max;
        return max;
    }
    int longestArithSeqLength(vector<int> &A)
    {
        mat.clear();
        int size = A.size();
        int max = -1;
        for (size_t i = 0; i < size; i++)
        {
            int tmp_max = 0;
            for (size_t j = i + 1; j < size; j++)
            {
                auto t = count(A, j, A[i] - A[j]) + 1;
                if (t > tmp_max)
                {
                    tmp_max = t;
                }
            }


            if( tmp_max > max){
                max = tmp_max;
            }
        }

        return max == -1 ? 0 : (1+max);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.longestArithSeqLength(vector<int>({9,4,7,2,10})));
    printf("%d\n", s.longestArithSeqLength(vector<int>({})));
    printf("%d\n", s.longestArithSeqLength(vector<int>({1})));
    printf("%d\n", s.longestArithSeqLength(vector<int>({1,2})));
    printf("%d\n", s.longestArithSeqLength(vector<int>({20, 1, 15, 3, 10, 5, 8})));

    return 0;
}
