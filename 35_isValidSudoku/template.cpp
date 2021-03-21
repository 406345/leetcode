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

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9;
        int col = 9;

        unordered_map<int,unordered_set<char>> small_sudo;
        unordered_set<char> r_set;

        int test = 1 ^ 11 ^ 151 ^ 123125^ 1;
        
        for (size_t i = 0; i < row; i++)
        {
            r_set.clear();
            for (size_t j = 0; j < col; j++)
            {
                if( board[i][j] == '.') continue;
                
                int nx = j / 3;
                int ny = i / 3;

                int mid = ny*3 + nx;

                if(small_sudo[mid].find(board[i][j]) != small_sudo[mid].end()){
                    return false;
                }
                else{
                    small_sudo[mid].insert(board[i][j]);
                }

                if(r_set.find(board[i][j]) != r_set.end()){
                    return false;
                }
                else{
                    r_set.insert(board[i][j]);
                }
            }
        }

        for (size_t i = 0; i < col; i++)
        {
            r_set.clear();
            for (size_t j = 0; j < row; j++)
            {
                if( board[j][i] == '.') continue;
                
                if(r_set.find(board[j][i]) != r_set.end()){
                    return false;
                }
                else{
                    r_set.insert(board[j][i]);
                }
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.isValidSudoku(vector<vector<char>>{
        vector<char>{'5','3','.','.','7','.','.','.','.'},
        vector<char>{'6','.','.','1','9','5','.','.','.'},
        vector<char>{'.','9','8','.','.','.','.','6','.'},
        vector<char>{'8','.','.','.','6','.','.','.','3'},
        vector<char>{'4','.','.','8','.','3','.','.','1'},
        vector<char>{'7','.','.','.','2','.','.','.','6'},
        vector<char>{'.','6','.','.','.','.','2','8','.'},
        vector<char>{'.','.','.','4','1','9','.','.','5'},
        vector<char>{'.','.','.','.','8','.','.','7','9'},
    });
    return 0;
}
