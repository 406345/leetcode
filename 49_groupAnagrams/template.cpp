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
    unordered_map<string,vector<int>> m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ret;

        for (size_t i = 0; i < strs.size(); i++)
        {
            string tmp = string(strs[i]);
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(i);
        }
        

        for(auto& kv : m){
            auto tmp = vector<string>();
            for(auto& idx : kv.second){
                tmp.push_back(strs[idx]);                
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.groupAnagrams(vector<string>{"eat","tea","tan","ate","nat","bat","abd","bdc","qevc","acac","caca","asd","daas","afg","gfa"});
    return 0;
}
