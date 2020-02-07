#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"
using namespace std;

class Solution {
public: 
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if( k == 0) return 0;
        int size = s.length();
        int left=0, right=0;
        int ret= 0;
        map<char,int> coll;
            
        while(left<size && right < size && left <= right){
            coll[s[right]] = right;

            if(coll.size() > k) {
                ret = max(ret,right-left);
                int minv = size;
                for(auto &kv : coll){
                    minv = min(kv.second,minv);
                }
                coll.erase(s[minv]);
                left=minv+1;
            }

            ++right;
        }

        ret = max(ret,right-left);
                
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("eceba", 2));
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("abbbbbbaaaaaaaaaaaaaaaaaaa", 0));
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("a", 34));
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("aeceba", 2));
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("aaaa", 2));
    printf("%d\n",s.lengthOfLongestSubstringKDistinct("abbbbbbaaaaaaaaaaaaaaaaaaa", 2));

    return 0;
}
