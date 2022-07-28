/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution
{
public:
    TreeNode *solve(TreeNode *root, int n1, int n2)
    {

        // base case
        if (root == NULL)
            return NULL;
        if (root->val == n1 || root->val == n2)
            return root;
        // since a node can be a descendant of itself also.

        TreeNode *leftAns = solve(root->left, n1, n2);
        TreeNode *rightAns = solve(root->right, n1, n2);

        if (leftAns != NULL && rightAns != NULL)
            return root;
        else if (leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if (rightAns != NULL && leftAns == NULL)
            return rightAns;

        return NULL;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int n1 = p->val;
        int n2 = q->val;

        TreeNode *ans = solve(root, n1, n2);
        return ans;
    }
};

/*
Given a Binary Tree with all unique values and two nodes value, n1 and n2.
The task is to find the lowest common ancestor of the given two nodes. We may
 assume that either both n1 and n2 are present in the tree or none of them are present.

Example 1:

Input:
n1 = 2 , n2 = 3
       1
      / \
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5
          /
         2
        / \
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2.
Your Task:
You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output.

Expected Time Complexity:O(N).
Expected Auxiliary Space:O(Height of Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/