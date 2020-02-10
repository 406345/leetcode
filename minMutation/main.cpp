#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"
#include "queue"
using namespace std;
 
class Solution
{
public: 
    set<string> bankset;
    int mut(string& start,string end,int deep){
        int size = start.length();
        int ret = 0xFFFF;
        if(start == end)return deep;
        for (size_t i = 0; i < size; i++)
        {
            if( start[i] == end[i]){
                continue;
            }

            auto ori = start[i];
            start[i] = end[i];

            if( bankset.find(start) == bankset.end()){
                start[i] = ori;
                continue;
            }

            ret = min(ret,mut(start,end,deep+1));
            start[i] = ori;
        }
        return ret;
    }
    int minMutation(string start, string end, vector<string> &bank)
    {
        for (auto &b : bank)
        {
            bankset.insert(b);
        }

        int ret = 999 ;
        for (size_t i = 0; i < bank.size(); i++)
        {
            auto m = mut(start,bank[i],0);
            auto n = mut(bank[i],end,0);
            ret = min(n+m,ret);
        }
         
        return  ret == 999 ? -1 : ret;
    }
};
int main(int argc, char const *argv[])
{ 
    Solution s;
    s.minMutation("ACC","ACA",vector<string>({"ACA"}));
}
