#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;
 
class HitCounter {
public:
    map<int,size_t> counter;
    size_t timer = 1;
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        counter[timestamp] =  counter[timestamp] + 1;

        while(counter.size() > 300){
            counter.erase(counter.begin());
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        size_t ret  = 0;
        int start = timestamp - 300;
        for(auto & kv : counter)
        {
            if( start < kv.first && kv.first <= timestamp)
            {
                ret += kv.second;
            } 
        }

        return ret;
        
    }
};

int main(int argc, char const *argv[])
{
    HitCounter s;
    s.hit(1);
    s.hit(2);
    s.hit(3);
    s.getHits(4);
    s.hit(300);
    s.getHits(300);
    s.getHits(301);
    return 0;
}
