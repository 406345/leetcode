#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"

using namespace std;

struct Num{
    int val;
    int index;

    Num(int v,int i):val(v),index(i){}


    bool operator< (const struct Num & n) const{
        if( n.val == this->val ){
            return n.index > this->index;
        }
        else 
            return n.val > this->val;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    { 
        set<Num> numbers;
        int count = 0;
        int size = nums.size();

        for (auto n : nums)
        {
            numbers.insert(Num(n,count++));
        }

        count = 0;

        for (auto& n : numbers)
        {
            if (count++ == (size-k))
            {
                return n.val;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.findKthLargest(vector<int>({-1,-1}), 2));
    printf("%d\n", s.findKthLargest(vector<int>({9, 9, 8, -1, 2, 3, 5, 5, 2, 3, 4, 1}), 3));

    return 0;
}
