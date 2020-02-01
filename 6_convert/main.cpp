#include "stdio.h"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    inline void print(char** matrix, int row,int col){
        return;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if( matrix[i][j] == 0){
                    printf(" ");
                }
                else printf("%c",matrix[i][j]);
            }

            printf("\n");
            
        }
        printf("============================\n");
    }
    string convert(string s, int numRows)
    {
        if( s.length() == 0)return "";

        if(numRows<=1)return s;
        char **matrix = new char *[numRows];

        for (size_t i = 0; i < numRows; i++)
        {
            matrix[i] = new char[s.length()]{0};
        }
        string ret = s;

        int ssize = s.length();
        int idx = 0;
        int rowIdx = 0;
        int colIdx = 0;
        int state =0 ;
        while (idx < ssize)
        {
            switch (state)
            {
            case 0:
                
                matrix[rowIdx][colIdx] = s[idx++];
                ++rowIdx;
                
                if(rowIdx == numRows){
                    rowIdx = numRows - 2;
                    ++colIdx;
                    state = 1;
                    print(matrix,numRows,ssize);
                }
                
                break;
            case 1:{
               
                if( rowIdx <= 0 ){
                    state = 0;
                    rowIdx = 0;
                    print(matrix,numRows,ssize);
                }
                else{
                     matrix[rowIdx][colIdx] = s[idx++];
                    --rowIdx;
                    ++colIdx;
                }
            }
            default:
                break;
            }
        }

        idx = 0;
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < ssize; j++)
            {
                if( matrix[i][j] != 0){
                    ret[idx++] = matrix[i][j];
                }
            }
            
        }
        

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.convert("ABCD", 2));
printf("%d\n", s.convert("LEETCODEISHIRING", 4));

    return 0;
}
