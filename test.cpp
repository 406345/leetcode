#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"
#include "fstream" 

using namespace std;
 
int main(int argc, char const *argv[])
{
    fstream f1 ;
    f1.open("D:\\demo1.2.d", ios::in);
    fstream f2 ;
    f2.open("D:\\demo1_full.2.d", ios::in);

    unordered_map<size_t,int> s1;
    unordered_map<size_t,int> s2;
    string line;
    char buffer[1024];
    while(!f1.eof()){
        f1.getline(buffer,1024);
        size_t k = atoll(buffer);
        s1[k] = 1+ s1[k];
    }

    while(!f2.eof()){
        f2.getline(buffer,1024);
        size_t k = atoll(buffer);
        s2[k] = 1+ s2[k];

        if(s2[k]>1){
            printf("%lld\n",k);
        }
    } 

    
    int hitCount = 0;
    int sc_id = 0;
    for(auto& d : s1){
        if( s2.find(d.first) != s2.end()){
            ++hitCount;
            printf("found scene=%d d=%lld shown=%d\n",sc_id, d.first, s2[d.first]);
        }
        sc_id++;
    }

    printf("collection 1 count=%d\n",s1.size());
    printf("collection 2 count=%d\n",s2.size());
    printf("hit count=%d\n",hitCount);

    
    return 0;
}
