#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"
#include "string"
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ret;
        for (size_t i = 1; i <= n; i++)
        {
            int a = i % 3;
            int b = i % 5;
            if (a == b && a == 0)
            {
                ret.push_back("FizzBuzz");
            }
            else if (a == 0)
            {
                ret.push_back("Fizz");
            }
            else if (b == 0)
            {
                ret.push_back("Buzz");
            }
            else{
                ret.push_back(to_string(i));
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.fizzBuzz(15);
    return 0;
}
