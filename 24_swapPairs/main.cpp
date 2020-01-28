#include "stdio.h"
#include "vector"
#include "unordered_map"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *p = nullptr;
        auto fst = head;
        auto sec = head->next;
        ListNode *newHead = nullptr;

        while (fst != nullptr && sec != nullptr)
        {
            auto tail = sec->next;
            auto tmp = sec;
            sec = fst;
            fst = tmp;

            if (p != nullptr)
                p->next = fst;

            fst->next = sec;
            sec->next = tail;

            if (newHead == nullptr)
                newHead = fst;

            p = sec;
            fst = sec->next;

            if (fst == nullptr)
                break;
            sec = fst->next;
        }

        if (newHead == nullptr)
            return head;

        return newHead;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *p = new ListNode(1);
    auto ph = p;

    auto t = s.swapPairs(p);

    return 0;
}
