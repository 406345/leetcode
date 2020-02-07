#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;

struct Days{
    long long begin;
    long long end;
    Days(long long b, long long e):begin(b),end(e){}

    bool operator<(const struct Days days)const{
        return true;
    }
};
class MyCalendar {
public:
    set<Days> days;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool isOK = true;
        for(auto& d : days){
            if( end <= d.begin )
                continue;

            if(start >= d.end)
                continue;

            return false;
        }

        if(isOK){
            days.insert(Days(start,end));
        }

        return isOK;
    }
};


int main(int argc, char const *argv[])
{
    MyCalendar s;
    s.book(47,50);
    s.book(33,41);
    s.book(39,45);
    s.book(33,42);
    s.book(25,32);
    s.book(26,35);
    s.book(19,25);
    s.book(3,8);
    s.book(8,13);
    s.book(18,27);
    return 0;
}
