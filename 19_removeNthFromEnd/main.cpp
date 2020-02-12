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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> nodes;
        auto p = new ListNode(0);
        auto t = p;
        t->next = head;

        while(t!=nullptr){
            nodes.push(t);
            t = t->next;

            if( nodes.size() >= n+2){
                nodes.pop();
            }
        }
        
        if(nodes.size() > 0 && nodes.front()->next!=nullptr) 
            nodes.front()->next = nodes.front()->next->next;

        return p->next; 
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode* i = new ListNode(1);
    auto p = i;
    for (size_t i = 2; i <= 5; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    
    s.removeNthFromEnd(i,1);

    return 0;
}
