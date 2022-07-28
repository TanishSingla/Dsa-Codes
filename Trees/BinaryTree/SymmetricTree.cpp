

// Symmetric Tree :-
bool sol(TreeNode *r1, TreeNode *r2)
{
    // if both nodes become NULL.
    if (r1 == NULL && r2 == NULL)
        return true;
    // if any 1 node is null but second one is not or if there value doesnt match we will rerturn 0.
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL) || (r1->val != r2->val))
        return false;
    return sol(r1->left, r2->right) && sol(r1->right, r2->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return sol(root->left, root->right);

    // example :-
    /*
        1
     2     2
  3    4 4     3
as this tree is symmetric.
we have called the function for (root->left,root->right)
means (r1 is 2 (left of 1)  and r2 is also 2(right of 1) )
as they are not null and there values are also equal so any of if statement will not execute.

then return statement will execute sol(2->left(3), 2->right(3))..returned true.{After that && statement will run i.e
sol(2->right,2->left)which will also return true.}
            👆
//sol(3->left,3->right)->both NULL return true;


    */
}

// Invert A binary Tree :-

Treenode *invert(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    TreeNode(root->left);
    TreeNode(root->right);
}