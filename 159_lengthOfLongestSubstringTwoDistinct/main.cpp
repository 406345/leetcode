#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"

using namespace std;
class Solution {
public:
    inline int count(string& s,int pos){
        int start = pos;
        int size = s.length();
        set<char> chars;
        
        while(pos<size){

            if(chars.find(s[pos]) == chars.end())
                chars.insert(s[pos]); 

            if(chars.size() > 2){
                break;
            }

            ++pos;
        }

        return pos-start;

    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int size = s.size();
        int count = 0;
        for (size_t i = 0; i < size; i++)
        {
            auto c = this->count(s,i);
            if(c>count){
                count = c;
            }
        }

        return count;   
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.lengthOfLongestSubstringTwoDistinct("eceba");

    return 0;
}
