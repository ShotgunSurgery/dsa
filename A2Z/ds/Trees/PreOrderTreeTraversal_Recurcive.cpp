#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> np;
    stack<TreeNode *> right;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if(!root && right.empty()) return np;
        else{
            np.push_back(root->val);
            if(root->right) right.push(root->right);
            if(root->left){
                root = right.top();
                right.pop();
            }
            preorderTraversal(root);
        }
        return np;
    }
};