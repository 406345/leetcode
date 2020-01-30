#include "stdio.h"
#include "vector"
#include "queue"
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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> ret;
        queue<ListNode *> box;
        auto p = root;
        int count = 0;

        while (p != nullptr)
        {
            // box[count] = p;
            ++count;
            p = p->next;
        }

        p = root;
        auto lp=p;
        int unitSize = (count) / k;
        int leftSize = count - (k * unitSize);

        for (int i = 0; i < k; i += 1)
        {
            ret.push_back(p);
            
            for (int j = 0; j < unitSize; j++)
            {
                lp = p;
                if (p != nullptr)
                    p = p->next;
            }

            if (leftSize > 0)
            {
                lp = p;
                if (p != nullptr)
                    p = p->next;

                --leftSize;
            }
 
            if(lp!=nullptr)
                lp->next = nullptr; 
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    ListNode *root = new ListNode(1);
    auto p = root;

    for (size_t i = 2; i <= 10; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }

    Solution s;
    s.splitListToParts(root,3);

    return 0;
}
