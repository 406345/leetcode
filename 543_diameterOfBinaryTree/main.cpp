#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

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
    int m = 0;
    int visit(TreeNode *root, int deep)
    {
        if (root == nullptr)
            return -1;

        int left = deep;
        int right = deep;

        left = visit(root->left, 0) + 1;
        right = visit(root->right,0) + 1;

        int sum = left + right;

        m = max(m, sum);

        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        m = max(m, visit(root, 0));
        return m;
    }
};
int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    s.diameterOfBinaryTree(nullptr);

    return 0;
}
