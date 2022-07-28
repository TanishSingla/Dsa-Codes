/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/
// T.C -> O(n)
// Celebrity Problem

class Solution
{

private:
    bool knows(vector<vector<int>> &M, int n, int a, int b)
    {
        if (M[a][b] == 1)
            return true;
        return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        // step - 1
        // we will pick two element at a time
        // and will check
        // at last in stack there will be 1 element present

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            // if a knows b then we will discard a and will add b
            if (knows(M, n, a, b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int celebrity = s.top();

        // Now we will check if he is celebrity or not
        // as to be a celebrity
        // 1. He should be known by everyone
        // which means that particular column should be 1 except
        // the diagobal element
        // 2. He shouldn't know anyone
        // for this,tht particular row should be 0

        int rowCt = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[celebrity][i] == 0)
                rowCt++;
        }
        if (rowCt != n)
            return -1;

        int colCt = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][celebrity] == 1)
                colCt++;
        }
        if (colCt != n - 1)
            return -1;

        return celebrity;
    }
};