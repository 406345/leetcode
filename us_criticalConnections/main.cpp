#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "map"
#include "set"

using namespace std;

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        int **matrix = new int *[n];
        for (size_t i = 0; i < n; i++)
        {
            matrix[i] = new int[n]{0};
        }

        for (size_t j = 0; j < n; j++)
        {
            matrix[connections[j][0]][connections[j][1]] = 1;
            matrix[connections[j][1]][connections[j][0]] = 1;
        }

        

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> ret;
        map<int, int> links;

        for (auto &cnn : connections)
        {
            links[cnn[0]] = links[cnn[0]] + 1;
            links[cnn[1]] = links[cnn[1]] + 1;
        }

        set<int> serverId;

        for (auto &kv : links)
        {
            if (kv.second == 1)
            {
                serverId.insert(kv.first);
            }
        }

        for (auto &cnn : connections)
        {
            if (serverId.find(cnn[0]) != serverId.end() ||
                serverId.find(cnn[1]) != serverId.end())
            {
                ret.push_back(vector<int>({cnn[0], cnn[1]}));
            }
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.criticalConnections(4, vector<vector<int>>({
                                                vector<int>({0, 1}),
                                                vector<int>({1, 2}),
                                                vector<int>({2, 0}),
                                                vector<int>({1, 3}),
                                                vector<int>({3, 4}),
                                                vector<int>({4, 5}),
                                                vector<int>({5, 3}),
                                            })));

    return 0;
}
