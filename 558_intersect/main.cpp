#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution
{
public: 

    Node *intersect(Node *q1, Node *q2)
    {
        if (q1->isLeaf || q2->isLeaf)
        {
            if (q1->isLeaf && q2->isLeaf)
            {
                bool r = q1->val || q2->val;
                return new Node(r, true, nullptr, nullptr, nullptr, nullptr);
            }
            if (q1->isLeaf)
            {
                if (q1->val == false)
                    return q2;
                else
                    return q1;
            }
            else if (q2->isLeaf)
            {
                if (q2->val == false)
                    return q1;
                else
                    return q2;
            }
        }

        Node *ret = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
        ret->topLeft = intersect(q1->topLeft, q2->topLeft);
        ret->topRight = intersect(q1->topRight, q2->topRight);
        ret->bottomLeft = intersect(q1->bottomLeft, q2->bottomLeft);
        ret->bottomRight = intersect(q1->bottomRight, q2->bottomRight);

        //判断 如果四个节点都为叶子节点，且值都相等 则合并为一个主节点
        bool hebing = false;
        if (ret->topLeft->isLeaf && ret->topRight->isLeaf && ret->bottomLeft->isLeaf && ret->bottomRight->isLeaf)
        {
            if (ret->topRight->val == ret->topLeft->val && ret->bottomLeft->val == ret->topLeft->val && ret->bottomRight->val == ret->topLeft->val)
            {
                ret->isLeaf = true;
                ret->val = ret->topLeft->val;
                ret->topLeft = ret->topRight = ret->bottomLeft = ret->bottomRight = nullptr;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    Node *n1 = new Node(true, false,
                        new Node(true, true, nullptr, nullptr, nullptr, nullptr),
                        new Node(true, true, nullptr, nullptr, nullptr, nullptr),
                        new Node(false, true, nullptr, nullptr, nullptr, nullptr),
                        new Node(false, true, nullptr, nullptr, nullptr, nullptr));

    Node *n2 = new Node(true, false,
                        new Node(true, true, nullptr, nullptr, nullptr, nullptr),
                        new Node(false, false,
                                 new Node(false, true, nullptr, nullptr, nullptr, nullptr),
                                 new Node(false, true, nullptr, nullptr, nullptr, nullptr),
                                 new Node(true, true, nullptr, nullptr, nullptr, nullptr),
                                 new Node(true, true, nullptr, nullptr, nullptr, nullptr)),
                        new Node(true, true, nullptr, nullptr, nullptr, nullptr),
                        new Node(false, true, nullptr, nullptr, nullptr, nullptr));

    s.intersect(n1, n2);

    return 0;
}
