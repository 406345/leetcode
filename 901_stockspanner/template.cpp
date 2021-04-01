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
#include "ctime"
#include "assert.h"

#define TIME(x)                                                    \
    {                                                              \
        int tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC);    \
        x;                                                         \
        tick = (int)(std::clock() * 1000 / CLOCKS_PER_SEC) - tick; \
        printf("cost %d(ms)\n", tick);                             \
    }

using namespace std;

class StockSpanner
{
private:
    struct StockElement
    {
        int price;
        int count;
    };

public:
    vector<int> stocks;
    int cur = 0;
    StockSpanner()
    {
        stocks.resize(150000);
    }

    inline int insert(vector<int> &s, int price)
    { 
        int sum = 0;
        s[cur] = price;


        for(int i = cur;i>=0;--i){
            if( price >= s[i]){
                ++sum;
            }
            else break;
        }

        ++cur;
        return sum;
    };

    int next(int price)
    {
        return insert(stocks, price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(int argc, char const *argv[])
{
    int ret = 0;
    StockSpanner s;


TIME(
    for (size_t i = 0; i < 150000; i++)
    {
        ret = s.next(rand()% 10000);
    }
);
    
    // ret = s.next(100);
    // ret = s.next(90);
    // ret = s.next(60);
    // ret = s.next(80);
    // ret = s.next(70);
    // ret = s.next(75);
    // ret = s.next(65);
    // ret = s.next(50);
    // ret = s.next(40);

    return 0;
}
