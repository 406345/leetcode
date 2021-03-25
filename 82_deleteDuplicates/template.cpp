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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    inline void forward(ListNode **p)
    {
        if (*p == nullptr)
            return;
        *p = (*p)->next;
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;

        auto root = new ListNode(head->val - 1);
        root->next = head;
        auto pre = root;
        auto cur = head;
        auto tail = cur->next;

        while (cur != nullptr)
        {
            if (tail != nullptr && cur->val == tail->val)
            {
                forward(&tail);
            }
            else
            {
                if (cur->next != tail)
                {
                    pre->next = tail;
                    cur = tail;
                    forward(&tail);
                }
                else{
                    forward(&pre);
                forward(&cur);
                forward(&tail);
                }
            }
        }

        return root->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    auto value = vector<int>{
        1,1,1,1,2,3,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,7,8,9,10,10,10,10
    };
    auto p = new ListNode(value[0]);
    auto head = p;
    for (size_t i = 1; i < value.size(); i++)
    {
        p->next = new ListNode(value[i]);
        p = p->next;
    }

    s.deleteDuplicates(head);
    return 0;
}
