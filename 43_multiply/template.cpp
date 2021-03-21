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
    string multiply(string num1, string num2)
    {
        string ret;
        vector<int> result;
        int c = num1.size() + num2.size();
        result.resize(c);
        int len = min(num1.size(), num2.size());

        int c1 = num1.size();
        int c2 = num2.size();

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        for (int i = 0; i < c1; i++)
        {
            auto n1 = num1[i] - '0';
            for (int j = 0; j < c2; j++)
            {
                auto n2 = num2[j] - '0';
                result[i + j] = result[i + j] + n1 * n2;
            }
        }

        for (int i = 0; i < c - 1; ++i)
        {
            result[i + 1] = result[i + 1] + result[i] / 10;
            result[i] = result[i] % 10;
        }

        int s = result.size() - 1;

        for (int i = result.size() - 1; i > 0; --i)
        {
            if (result[i] == 0)
            {
                s = i-1;
            }
            else{break;}
        }

        for (int i = s; i >= 0; i--)
        { 
            ret += '0' + result[i] ;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string result;
    result = s.multiply("100000000", "40000000");
    result = s.multiply("9000000", "20000000");
    result = s.multiply("999999", "0");
    result = s.multiply("999", "999");
    result = s.multiply("12342351253123512", "1");
    return 0;
}
