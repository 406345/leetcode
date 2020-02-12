#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        set<int> numbers;
        numbers.insert(0);

        for(auto& w : wall){
            int size = w.size();
             numbers.insert(w[0]);
            for (size_t i = 1; i < size; i++)
            {
                w[i] += w[i-1];
                 numbers.insert(w[i]);
            } 
        }
        int rows = wall.size();
        int size = wall[0].size();
        int right = wall[0][size-1];
        size_t* idx = new size_t[rows+2]{0};
        size_t* counter = new size_t[numbers.size()]{0};
        int cid = 0;
        for(auto i : numbers)
        { 
            for (size_t j = 0; j < rows; j++)
            {
                int rsize = wall[j].size();
                if( idx[j] < rsize && wall[j][idx[j]] > i ){
                    counter[cid] += 1;
                }
                else{
                    idx[j] += 1;
                }
            }
            ++cid;
        }
        
        size_t ret = INT_MAX;
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            printf("%d ", counter[i]);
            ret = min(ret,counter[i]);
        }
        

        return (int)ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.leastBricks(vector<vector<int>>({
        
        vector<int>({100000000}),
        vector<int>({100000000}),
        vector<int>({100000000}), 

    }));

    s.leastBricks(vector<vector<int>>({
        
        vector<int>({1,2,2,1}),
        vector<int>({3,1,2}),
        vector<int>({1,3,2}),
        vector<int>({2,4}),
        vector<int>({3,1,2}),
        vector<int>({1,3,1,1}),

    }));

     s.leastBricks(vector<vector<int>>({
        vector<int>({1,1,1}),
    }));
 

    return 0;
}
