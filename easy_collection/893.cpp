#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "map"
#include "set"
#include "string"

using namespace std;

class Solution {
public:
    inline string array_to_string(size_t* buf,int size){
        string ret;

        for (size_t i = 0; i < size; i++)
        {
            ret += to_string(buf[i]);
        }
        
        return ret;
    }
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> ret;
        for(auto& str : A){
            char buf[56] = {0};

            int s = str.size();

            for (size_t i = 0; i < s; i++)
            {
                buf[str[i] - 'a' + 26*(i%2)] += 1;
            }
            
            ret.insert(array_to_string((size_t*)buf,7));
        }
        return ret.size();
    }
};

int main(int argc, char const *argv[])
{
    //ababaa
    //aaabaa
    Solution s;
    // s.numSpecialEquivGroups(vector<string>{ });
    s.numSpecialEquivGroups(vector<string>{  "ababaa","aaabaa"});
    s.numSpecialEquivGroups(vector<string>{  "aabbb","aabba"});
    s.numSpecialEquivGroups(vector<string>{  "a","a"});
    s.numSpecialEquivGroups(vector<string>{  "a","b","c","a","c","c" });
    return 0;
}
