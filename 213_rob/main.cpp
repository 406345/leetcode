#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "queue"
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int m = 0;
        int size = nums.size();

        if( size == 0 ) return 0;
        if( size == 1 ) return nums[0];

        int *box1 = new int[nums.size()+2];
        int *box2 = new int[nums.size()+2];

        box1[0] = nums[0];
        box1[1] = nums[0];
        box2[0] = 0;
        box2[1] = nums[1];

        for (int i = 2; i < size; i++)
        {
            box1[i] = max( box1[i-1],  box1[i-2] + nums[i] );
            box2[i] = max( box2[i-1],  box2[i-2] + nums[i] );
        }

        return max(box1[size-2], box2[size-1]);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.rob(vector<int>({155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,242,157,79,133,66,36,165})));
    printf("%d\n", s.rob(vector<int>({99, 99, 98, 1, 2, 3, 4})));
    printf("%d\n", s.rob(vector<int>({1, 2, 1, 1})));
    printf("%d\n", s.rob(vector<int>({1, 1, 1, 1})));
    printf("%d\n", s.rob(vector<int>({1, 2, 3, 1})));
    printf("%d\n", s.rob(vector<int>({4, 1, 2, 7, 5, 3, 1})));
    printf("%d\n", s.rob(vector<int>({2, 3})));

    return 0;
}
