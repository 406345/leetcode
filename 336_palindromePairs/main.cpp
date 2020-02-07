#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    inline bool is_palin(vector<string>& words,int a,int b){
        int l = 0, r = words[a].length() + words[b].length() - 1;
        int asize = words[a].length();
        int bsize = words[b].length();
        int size = asize + bsize;

        //if( abs((int)words[a].length() - (int)words[b].length()) > 1 )return false;

        while(l < r && l < (size) && r>0){
            char ca,cb;
            if( l < asize){
                ca = words[a][l];
            }else{
                ca = words[b][l - asize];
            }

            if( r >= asize){
                cb = words[b][r-asize];
            }else{
                cb = words[a][r];
            }

            if( ca != cb)
                return false;

            ++l;
            --r;
        }

        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int size = words.size();
        vector<vector<int>> ret;
        for (int i = 0; i < size-1; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if(this->is_palin(words,i,j)){
                    ret.push_back(vector<int>{i,j});
                }
                if(this->is_palin(words,j,i)){
                    ret.push_back(vector<int>{j,i});
                }
            }
            
        }

        return ret;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.palindromePairs(vector<string>({"abcd","dcba","lls","s","sssll"})));

    return 0;
}
