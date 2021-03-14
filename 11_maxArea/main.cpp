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
    int maxArea(vector<int> &height)
    {
        int ret = 0;
        int size = height.size();
        int front=0,end=size-1,left,right,s;
        while(front<end){
            left = height[front];
            right = height[end];
            ret = max(ret, (end-front)*min(left,right));
            
            if(left<right){
                ++front;
            }
            else{
                --end;
            }
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    int t = 0;
    t = s.maxArea(vector<int>{1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1});
    t = s.maxArea(vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7});
    t = s.maxArea(vector<int>{1,2,1});
    t = s.maxArea(vector<int>{1,1});
   
    return 0;
}
