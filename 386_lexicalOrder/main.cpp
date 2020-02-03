#include "stdio.h"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    void compute(vector<int> &ret, int prefix, int n)
    {
        for (size_t i = 0; i <= 9; i++)
        {
            int cur = prefix * 10 + i;

            if(cur > n)break;


            ret.push_back(cur);
            compute(ret, cur, n);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ret;
        for (int i = 1; i <= 9; i++)
        {
            if (i <= n)
            {
                ret.push_back(i);
                compute(ret, i, n);
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.lexicalOrder(2));
    printf("%d\n", s.lexicalOrder(100));

    return 0;
}
