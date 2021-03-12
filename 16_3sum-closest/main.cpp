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

class Solution
{
public:
    struct Num
    {
        int sum;
        int x, y;
    };
  
    int threeSumClosest(vector<int> &nums, int target)
    {
        unordered_map<int,Num> mid;

        // mid.resize(nums.size()*2);

        int size = nums.size();

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                mid[nums[i] + nums[j]] = {
                    (nums[i] + nums[j]),
                    i, j};
            }
        }

        int msize = mid.size();
        int delta = 0xFFFFFFF;
        Num mi ;
        int ni = 0;

        for(auto & kv : mid)
        {
            for (int j = 0; j < size; j++)
            {
                if (kv.second.x == j || kv.second.y == j)
                {
                    continue;
                }

                int d = abs(target - (kv.first + nums[j]));

                if (d < delta)
                {
                    delta = d;
                    mi = kv.second;
                    ni = j;
                }
            }
        }
 
        // printf("nums %d %d %d = %d",  nums[mi.x], nums[mi.y], nums[ni], nums[mi.x]+ nums[mi.y] + nums[ni]);
        return  nums[mi.x]+ nums[mi.y] + nums[ni];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> i = {-88,-92,-82,-36,-1,67,13,83,87,-37,42,88,32,-14,56,-60,87,39,13,-37,86,-24,34,56,-16,-56,-49,-45,78,-77,22,-44,-21,42,-56,-81,-15,73,-78,3,-19,85,69,15,-21,46,62,84,-71,-49,36,0,100,34,34,3,-62,-54,-50,-9,-28,-12,-78,-4,-87,-7,-48,-40,46,-91,-77,32,-80,-1,55,32,32,-38,-5,56,-61,-81,-2,-22,-27,61,-4,75,79,80,-53,-49,-22,93,62,52,-44,98,-85,62,-64,-48,-82,51,-65,-25,75,-1,-94,-56,9,43,-5,-100,-92,-68,16,22,4,90,36,86,-55,-73,-48,-69,36,-76,-18,-99,-69,-65,14,48,59,19,-18,72,93,53,6,-63,-99,16,46,-93,-13,-66,42,-78,-84,-63,-68,-6,-11,-32,-12,26,66,94,-90,-59,75,-62,-72,-85,68,-23,-80,28,-55,-41,-88,10,-42,-31,22,100,47,-47,32,40,-77,68,58,13,-56,-12,-54,-63,-59,-93,15,11,51,13,21,15,82,-19,11,-51,-20,-77,18,-36,65,58,53,-75,-59,53,74,-43,16}; 
    s.threeSumClosest(i,168);

    return 0;
}
