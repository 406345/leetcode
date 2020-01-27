#include "stdio.h"
#include "vector"
using namespace std;
class Solution
{
private:
    inline bool isSameDirect(int a, int b)
    {
        return (a >> 31) == (b >> 31);
    }

public:
    vector<int> asteroidCollision(vector<int> &ast)
    {
        int size = ast.size();
        for (int i = 0; i < (size - 1);)
        {
            int next = (i + 1);

            if (next >= size)
                break;

            if (ast[i] > 0 && !isSameDirect(ast[i], ast[next]))
            {
                if ((-1 * ast[next]) > ast[i])
                {
                    // ast[i] = 0;
                    ast.erase(ast.begin() + i);
                    i = 0;
                    --size;
                    continue;
                }
                else if ((-1 * ast[next]) < ast[i])
                {
                    // ast[next] = 0;
                    ast.erase(ast.begin() + next);
                    i = 0;
                    --size;
                    continue;
                }
                else if ((-1 * ast[next]) == ast[i])
                {
                    // ast[next] = 0;
                    // ast[i] = 0;
                    ast.erase(ast.begin() + next);
                    ast.erase(ast.begin() + i);
                    i = 0;
                    size -= 2;
                    continue;
                }
            }
            ++i;
        }

        return ast;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input = {};

    Solution s;
    s.asteroidCollision(vector<int>({10, 2, -5}));
    s.asteroidCollision(vector<int>({-8, 8}));
    s.asteroidCollision(vector<int>({10, -5, 2}));
    s.asteroidCollision(vector<int>({5, 10, -5}));
    s.asteroidCollision(vector<int>({8, -8}));
    s.asteroidCollision(vector<int>({-2, -1, 1, 2}));
    s.asteroidCollision(vector<int>({}));

    return 0;
}
