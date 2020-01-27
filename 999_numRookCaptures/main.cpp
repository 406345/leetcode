#include "stdio.h"
#include "vector"

using namespace std;

class Solution
{
private:
    const int row = 8;
    const int col = 8;

public:
    int calculate(vector<vector<char>> &board, int x, int y)
    {
        int ret = 0;
        // forward: (1,0)
        for (int i = x + 1; i < col; i++)
        {
            if (board[y][i] == 'B')
            {
                break;
            }
            else if (board[y][i] == 'p')
            {
                ++ret;
                break;
            }
        }
        // forward: (-1,0)
        for (int i = x - 1; i > 0; i--)
        {
            if (board[y][i] == 'B')
            {
                break;
            }
            else if (board[y][i] == 'p')
            {
                ++ret;
                break;
            }
        }

        // forward: (0,1)
        for (int i = y + 1; i < row; i++)
        {
            if (board[i][x] == 'B')
            {
                break;
            }
            else if (board[i][x] == 'p')
            {
                ++ret;
                break;
            }
        }

        // forward: (0,1)
        for (int i = y - 1; i > 0; i--)
        {
            if (board[i][x] == 'B')
            {
                break;
            }
            else if (board[i][x] == 'p')
            {
                ++ret;
                break;
            }
        }

        return ret;
    };

    int numRookCaptures(vector<vector<char>> &board)
    {

        int sum = 0;

        for (int c = 0; c < col; c++)
        {
            for (int r = 0; r < row; r++)
            {
                if (board[r][c] == 'R')
                {
                    sum += calculate(board, c, r);
                }
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> input;
    input = {
        {
            '.',
            '.',
            '.',
            '.',
            '.',
            '.',
            '.',
            '.',
        },
        {
            ' ',
            'P',
            'P',
            'P',
            'P',
            'P',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            'B',
            'R',
            ' ',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            'P',
            'P',
            ' ',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
        },
        {
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
        },
    };

    s.numRookCaptures(input);

    return 0;
}
