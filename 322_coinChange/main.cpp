#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "algorithm"
#include "map"
using namespace std;

class Solution
{
public:
    map<int,int> memory;
    int change(vector<int> &coins, int amount)
    {
        if(amount<=0) return 0; 
        if(memory.find(amount)!=memory.end())return memory[amount];


        int size = coins.size();

        int min = 0x7FFFFFFF;

        for (size_t i = 0; i < size; i++)
        {
            auto left = amount - coins[i];
            if( left >= 0){
                auto step = change(coins, left) ;
                if( step< min && step >= 0){
                    min = step + 1;
                }
            } 
        }

        auto ret = min == 0x7FFFFFFF ? -1 : min;
        memory[amount] = ret;
        return ret;
        
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memory.clear();
        return change(coins,amount);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.coinChange(vector<int>({1,2,5}), 8));
    printf("%d\n", s.coinChange(vector<int>({186,419,83,408}), 6249));
    printf("%d\n", s.coinChange(vector<int>({2}), 3));

    return 0;
}
