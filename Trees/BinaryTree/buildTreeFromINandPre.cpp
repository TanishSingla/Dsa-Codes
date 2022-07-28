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

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStIndex, int inorderEndIndex, int n, map<int, int> &m)
    {

        // base case
        if (preIndex >= n || (inorderStIndex > inorderEndIndex))
            return NULL;

        // as starting ele of pre order will be root node.
        int ele = preorder[preIndex++];
        TreeNode *root = new TreeNode(ele);
        // we will find the position of that ele in inorder
        // and from its position, its left part will be left subtree
        // and right part will be right subtree.

        int position = m[ele];

        root->left = solve(preorder, inorder, preIndex, inorderStIndex, position - 1, n, m);
        root->right = solve(preorder, inorder, preIndex, position + 1, inorderEndIndex, n, m);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // pre-order = [root left right]
        // inorder = [left root right]

        // mapping of node to its index
        // so we can find that particular element in o(1) Time.
        map<int, int> m;
        mapping(m, inorder);

        // index for preorder
        int preOrderIndex = 0;
        int n = preorder.size();

        TreeNode *ans = solve(preorder, inorder, preOrderIndex, 0, n - 1, n, m);

        return ans;
    }
};