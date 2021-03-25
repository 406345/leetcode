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
        printf("cost %d(ms)", tick);                               \
    }

using namespace std;

class Solution
{
public:

    int findRoot(vector<int>& collection, int id){

        if( collection[id] == id) return id;
        
        return findRoot(collection, collection[id]);
    }

    void join(vector<int>& collection, int id1,int id2){
        // id2 adds to id1

        int root1 = findRoot(collection, id1);
        int root2 = findRoot(collection, id2);

        collection[root2] = root1;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int c = edges.size();
        vector<int> collection;
        collection.resize(c + 1);

        for (size_t i = 0; i < c + 1; i++)
        {
            collection[i] = i;
        }

        for (auto &e : edges)
        {
            int root_parent = findRoot(collection, e[0]);
            int children_parent = findRoot(collection, e[1]);

            if( root_parent == children_parent && root_parent >0){
                return e;
            }

            join(collection, e[0],e[1]);
             
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto input = vector<vector<int>>{
        {1, 5},
        {3, 4},
        {3, 5},
        {4, 5},
        {2, 4}};
    s.findRedundantConnection(input);
    return 0;
}
