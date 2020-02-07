#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    set<size_t> visit_list;
    map<int, vector<int>> nmap;
    void visit(Node *target)
    {
        if( target == nullptr)return;

        auto addr = (size_t)(target);

        if (visit_list.find(addr) != visit_list.end())
        {
            return;
        }

        visit_list.insert(addr);

        for (auto n : target->neighbors)
        {
            nmap[target->val].push_back(n->val);
            visit(n);
        }
    }
    Node *cloneGraph(Node *node)
    {
        if( node == nullptr ) return node;
        if( node != nullptr && node->neighbors.size() == 0 ){
            return new Node(node->val);
        }
        visit_list.clear();
        nmap.clear();

        visit(node);
        map<int,Node*> node_map;

        for(auto n : nmap){
            node_map[n.first] = new Node(n.first);    
        }

        for(auto n : nmap){
            for(auto nn : n.second){
                node_map[n.first]->neighbors.push_back(node_map[nn]);
            }
        }

        return node_map[node->val];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    Node* n1 = new Node(1);
    auto n2 = new Node(2);
    auto n4 = new Node(4);
    auto n3 = new Node(3);

    // n1->neighbors.push_back(n2);
    // n1->neighbors.push_back(n4);

    // n2->neighbors.push_back(n1);
    // n2->neighbors.push_back(n3);
    
    // n3->neighbors.push_back(n2);
    // n3->neighbors.push_back(n4);

    // n4->neighbors.push_back(n1);
    // n4->neighbors.push_back(n3);

    // s.cloneGraph(nullptr);
    s.cloneGraph(n1);
    return 0;
}
