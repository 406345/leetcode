#include "stdio.h"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret;
        int size = sizeof(uint32_t) * 8;

        for (size_t i = 0; i < size; i++)
        {
            auto ori = ((n >> i) & 1) ;
            
            ret += (ori << (size - (i + 1)));
        }

        // 964176192
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.reverseBits(1));
    printf("%d\n", s.reverseBits(43261596));

    return 0;
}
