#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;

bool compare(const string& a, const string& b){
    if(a.length() == b.length()){
        return a>b;
    }
    else return a.length() < b.length();
    
}
class Solution {
public:
    bool is_match(string& s,string& target){
        int ps = 0;
        int pt = 0;
        int ssize = s.size();
        int tsize = target.size();
        while(ps < ssize && pt < tsize){
            if( s[ps] != target[pt]){
                ++ps;
                continue;
            } 

            ++ps;
            ++pt;
        }

        return pt == tsize;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),compare);

        int size = d.size();
        string ret = "";

        for(int i=size-1;i>=0;--i){
            if(this->is_match(s,d[i])){
                if(ret.size() < d[i].size()){
                     ret = d[i];
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.findLongestWord("abpcplea",vector<string>({"a"}));
    s.findLongestWord("abpcplea",vector<string>({"ale","apple","monkey","plea"}));
    s.findLongestWord("abpcplea",vector<string>({"a","b", "c","aa","ab","cc"}));

    return 0;
}
