#include "stdio.h"
#include "vector"
#include "unordered_map"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *flt(TreeNode *r)
    {
        if (r == nullptr)
            return r;

        if (r->left == nullptr && r->right == nullptr)
            return r;

        auto ori = r->right;

        auto newl = flt(r->left);
        auto newr = flt(r->right);

        r->right = newl;
        r->left = nullptr;

        auto t = r;

        if (t == nullptr)
            return nullptr;

        while (t != nullptr && t->right != nullptr)
            t = t->right;

        t->right = newr;

        return r;
    }

    void flatten(TreeNode *root)
    {
        this->flt(root);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(5);
    t->left->left = new TreeNode(3);
    t->left->right = new TreeNode(4);
    t->right->right = new TreeNode(6);

    // TreeNode *t = new TreeNode(1);
    // t->right = new TreeNode(2);
    // t->right->left = new TreeNode(3);

    s.flatten(t);

    return 0;
}
