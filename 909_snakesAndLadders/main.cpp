#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "queue"
using namespace std;
struct Move
{
    int id;
    int count;
    Move(int i, int c) : id(i), count(c){};
};
class Solution
{
public:
    int matrix_size = 6;
    int matrix_total = 0;
    int pos2Id(int x, int y)
    {
        int id = y * 6 + 1;
        if (y % 2 != 0)
        {
            id += (5 - x);
        }
        else
        {
            id += x;
        }

        return id;
    }

    void id2Pos(int id, int *x, int *y)
    {
        auto row = (id - 1) / matrix_size;
        auto col = (id - 1) % matrix_size;
        *y = (matrix_size - 1) - row;
        if (row % 2 != 0)
        {
            *x = matrix_size - col - 1;
        }
        else
        {
            *x = col;
        }
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        matrix_size = board.size();
        matrix_total = matrix_size * matrix_size;
        int *matrix = new int[matrix_total + 1];
        queue<Move> ids;
        ids.push(Move(1, 0));

        for (size_t i = 0; i < (matrix_total + 1); i++)
        {
            matrix[i] = 0xFFFF;
        }

        int max = 0xFFFFF;

        while (ids.size() > 0)
        {
            auto m = ids.front();
            ids.pop();

            if(m.count>this->matrix_total){
                continue;
            }

            if (m.id == (matrix_total))
            {
                if (m.count < max)
                {
                    max = m.count;
                }
            }
            else
            {
                for (int step = 1; step <= 6; step++)
                {
                    auto mid = m.id + step;
                    if (mid > (matrix_total))
                        break;

                    int x = 0, y = 0;
                    this->id2Pos(mid, &x, &y);

                    if (board[y][x] != -1)
                    {
                        auto pos = board[y][x];
                        auto c = m.count + 1;
                        if (matrix[pos] > c)
                        {
                            matrix[pos] = c;
                            ids.push(Move(pos, c));
                        }
                    }
                    else
                    {
                        auto pos = mid;
                        auto c = m.count + 1;
                        if (matrix[pos] > c)
                        {
                            matrix[pos] = c;
                            ids.push(Move(pos, c));
                        }
                    }
                }
            }
        }

        return max > this->matrix_total ? -1:max;
    }
};

int main(int argc, char const *argv[])
{
    int i, j;
    Solution s;

    // vector<vector<int>> board;
    // for (size_t row = 0; row < 6; row++)
    // {
    //     board.push_back(vector<int>());
    //     for (size_t col = 0; col < 6; col++)
    //     {
    //         board[row].push_back(-1);
    //     }
    // }
    // board[5][1] = 15;
    // board[3][1] = 35;
    // board[3][4] = 13;

    vector<vector<int>> board;
    int size = 3;
    for (size_t row = 0; row < size; row++)
    {
        board.push_back(vector<int>());
        for (size_t col = 0; col < size; col++)
        {
            board[row].push_back(-1);
        }
    }
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
    board[2][1] = 1;
    board[2][2] = 1;

    s.snakesAndLadders(board);

    return 0;
}
