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
    int target;
    vector<vector<int>> ret;
    void visit(TreeNode *root, int sum, vector<int> &path)
    {
        if(root==nullptr)return;

        int total = sum + root->val;

        vector<int> n;
        for (auto &k : path)
        {
            n.push_back(k);
        }
        n.push_back(root->val);

        if (root->left != nullptr)
        {
            visit(root->left, sum + root->val, n);
        } 

        if (root->right != nullptr)
        {
            visit(root->right, sum + root->val, n);
        } 

        if(root->left == nullptr && root->right == nullptr){
            if (total == this->target)
            {
                this->ret.push_back(n);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        this->target = sum;
        vector<int> n;
        visit(root, 0, n);
        return this->ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* tn = new TreeNode(5);

    tn->left = new TreeNode(4);
    tn->right = new TreeNode(8);


    tn->left->left = new TreeNode(11);
    tn->left->left->left = new TreeNode(7);
    tn->left->left->right = new TreeNode(2);

    tn->right->left = new TreeNode(13);
    tn->right->right = new TreeNode(4);
    tn->right->right->left = new TreeNode(5);
    tn->right->right->right = new TreeNode(1);

    s.pathSum(tn,22);
    return 0;
}
