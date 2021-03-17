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

using namespace std;
class Solution
{
public:
    struct QElement
    {
        string str;
        int left, right;
    };

    vector<string> generateParenthesis(int n)
    {
        int left = n, right = n;
        vector<string> ret;
        queue<QElement> q; 
        q.push(QElement{"", n, n});

        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();

            if (tmp.left == 0 && tmp.right == 0)
            {
                ret.push_back(tmp.str);
                continue;
            }

            if (tmp.left > 0)
            {
                q.push(QElement{
                    tmp.str + "(",
                    tmp.left - 1,
                    tmp.right});
            }
            
            if (tmp.left < tmp.right)
            {
                q.push(QElement{
                    tmp.str + ")",
                    tmp.left,
                    tmp.right - 1});
            }
        }

        return ret;
    };
};

int
main(int argc, char const *argv[])
{
    Solution s;
    auto ret = s.generateParenthesis(3);

    return 0;
}
