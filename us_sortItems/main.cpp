#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = -1;
        int item = -1;
        set<int> done;

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if(group[j] == i && beforeItems[j].size() == 0){
                    groupId = i;
                    item = j;
                    done.insert(j);
                    break;
                }
            }
        }


    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.sortItems(8,2,vector<int>({-1,-1,1,0,0,1,0,-1}), vector<vector<int>>({
        vector<int>({}),
        vector<int>({6}),
        vector<int>({5}),
        vector<int>({6}),
        vector<int>({3,6}),
        vector<int>({}),
        vector<int>({}),
        vector<int>({}),
        })));

    return 0;
}
