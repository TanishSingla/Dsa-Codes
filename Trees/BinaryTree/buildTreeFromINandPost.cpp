/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void mapping(map<int, int> &m, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
    }

    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int &postIndex, int inorderStIndex, int inorderEndIndex, int n, map<int, int> &m)
    {

        // base case
        if (postIndex < 0 || (inorderStIndex > inorderEndIndex))
            return NULL;

        // as ending ele of post order will be root node.
        int ele = postorder[postIndex--];
        TreeNode *root = new TreeNode(ele);
        // we will find the position of that ele in inorder
        // and from its position, its left part will be left subtree
        // and right part will be right subtree.

        int position = m[ele];

        // first we are calling for right node
        // becoz we are traversing postorder from its last index. as
        // postorder = [left right node].
        root->right = solve(postorder, inorder, postIndex, position + 1, inorderEndIndex, n, m);
        root->left = solve(postorder, inorder, postIndex, inorderStIndex, position - 1, n, m);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        // inorder : - [left root right]
        // post order :- [ left right root]

        map<int, int> m;
        mapping(m, inorder);

        int n = postorder.size();
        // index for postorder
        // we will traverse postorder from its last
        // as preorder last index will b root node
        int postOrderIndex = n - 1;

        TreeNode *ans = solve(postorder, inorder, postOrderIndex, 0, n - 1, n, m);

        return ans;
    }
};