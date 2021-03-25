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
#include "ctime"
#include "assert.h"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)", tick);                               \
    }

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;
        string ret = "";
        int idx = s.size()-1;
        int state = 0;
        string tmp = "";
        while(idx>=0){
            switch (state)
            {
            case 0:

                if( s[idx] == ' '){
                    --idx;
                    continue;
                }
                else {
                    state = 1;
                    continue;
                }
                /* code */
                break;
            case 1:{
                if( s[idx] == ' '){
                    ret += tmp + " ";
                    tmp = "";
                    state = 0;
                    continue;
                }
                tmp = s[idx--] + tmp;
            }break;
            default:
                break;
            }
        }

        ret =  ret.substr(0,ret.size()-1);
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    assert(s.reverseWords("  hello world!  ") == "world! hello");
    assert(s.reverseWords(" the sky is blue  ") == "blue is sky the");
    assert(s.reverseWords("  Bob    Loves  Alice   ") == "Alice Loves Bob");
    return 0;
}
