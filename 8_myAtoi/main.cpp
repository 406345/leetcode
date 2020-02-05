#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int ret = 0;
        int size = str.size();
        bool nagetive = false;

        vector<int> nums ;
        int state = 0;

        for (int i = 0; i < size; i++)
        {
            switch (state)
            {
            case 0:
                if (str[i] == ' ')
                    continue;
                else  if(str[i] == '-'){
                    nagetive = -1;
                    state = 1;
                }
                else if( str[i] == '+' ){
                    state = 1;
                }
                else{
                    state = 1;
                    --i;
                };
                
                break;
            case 1:
              
                if (str[i] >= '0' && str[i] <= '9'){
                    nums.push_back(str[i]-'0');
                }
                else {
                    i = size;
                };
                default:
                    break;
            }
        }

        size = nums.size();

        for (size_t i = 0; i < size; i++)
        {
            ret += nums[i]*pow(10,size - i - 1);

            if( ret < 0){
                return nagetive ? INT_MIN : INT_MAX;
            }
        }

        return nagetive ? -ret : ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.myAtoi("-91283472332"));
    printf("%d\n", s.myAtoi("--123124"));
    printf("%d\n", s.myAtoi("      -123124"));
    printf("%d\n", s.myAtoi("abadc -123124"));
    printf("%d\n", s.myAtoi("-123 a  124"));

    return 0;
}
