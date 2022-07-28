// https://leetcode.com/problems/longest-valid-parentheses/
#include <iostream>
#include <stack>
using namespace std;

int longestValidParenthesis(string input)
{
    stack<int> s;
    s.push(-1);
    int len = input.length();
    int maxL = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = input[i];
        if (ch == '(')
            s.push(i);
        else
        {
            // close bracket
            s.pop();
            if (s.empty())
                s.push(i);
            else
            {
                maxL = max(maxL, i - s.top());
            }
        }
    }
    return maxL;
}
// T.C -> O(n)
// S.C -> O(n)

int longestValidParenthesis2(string input)
{
    int close = 0;
    int open = 0;
    int maxL = 0;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        if (ch == '(')
            open++;
        else
            close++;
        if (close == open)
            maxL = max(maxL, open + close);
        else if (close > open)
            close = open = 0;
    }
    open = close = 0;
    for (int i = input.length() - 1; i >= 0; i--)
    {
        char ch = input[i];
        if (ch == '(')
            open++;
        else
            close++;
        if (close == open)
            maxL = max(maxL, open + close);
        else if (open > close)
            close = open = 0;
    }
    return maxL;
}

int main()
{
    string s = ")()()(())";
    cout << longestValidParenthesis2(s) << '\n';
    return 0;
}