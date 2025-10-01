class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        vector<vector<vector<int>>> ans;

        if (!root)
            return false;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int curr_size = q.size();
            vector<vector<int>> curr_ans2;
            while (curr_size--)
            {
                TreeNode *pick = q.front();
                vector<int> curr_ans1;
                curr_ans1.push_back(pick->val);
                if (root->left != NULL)
                    q.push(pick->left);
                if (root->right != NULL)
                    q.push(pick->right);
                q.pop();
                curr_ans2.push_back(curr_ans1);
            }
            ans.push_back(curr_ans2);
        }

        int i = ans.size() - 1;
        if ((ans[i].size() < ans[i - 1].size()) == 0)
            return true;
        else
            return false;
    }
};