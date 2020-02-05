#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    long long min = INT_MAX;
    double delta = 9999999999;

    void visit(TreeNode* root, double& target){
        if( root == nullptr ) return;
        auto d = abs((double)root->val - target);

        if(d < delta){
            delta = d;
            min = root->val;
        }

        visit(root->left,target);
        visit(root->right,target);
    }
    int closestValue(TreeNode* root, double target) {
        min = INT_MAX;
        delta = 9999999999;

        visit(root,target);

        return min;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;


    TreeNode* tn = new TreeNode(4);

    tn->left  = new TreeNode(2);
    tn->left->left  = new TreeNode(1);
    tn->left->right  = new TreeNode(3);
    tn->right = new TreeNode(5);

    printf("%d\n",s.closestValue(tn,3.74));

    return 0;
}
