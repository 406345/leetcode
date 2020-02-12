#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;
struct Data{
    int val;
    vector<int> pos;
    int index = 0;
    Data(int v):val(v){}
 
};
class Solution {
public:
    unordered_map<int,Data*> meta;
    Solution(vector<int>& nums) {
        int size = nums.size();
        for (size_t i = 0; i < size; i++)
        { 
            if(meta.find(nums[i]) == meta.end()){
                meta[nums[i]] = new Data(nums[i]);
                meta[nums[i]]->index = 0;
                meta[nums[i]]->val = nums[i];
                meta[nums[i]]->pos.push_back(i);
            } 
            else{
                meta[nums[i]]->pos.push_back(i);
            }
        }
        
    }
    
    int pick(int target) {
        if( meta.find(target) == meta.end())return -1;

        auto d = meta[target];
        return d->pos[d->index++ % d->pos.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution s(vector<int>({1,2,3,3,3}));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));
    printf("%d\n",s.pick(3));

    return 0;
}
