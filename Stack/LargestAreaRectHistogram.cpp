// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {

        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {

            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {

        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++)
        {

            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {

        // we will find the next and previous smaller element
        // to get breadth as length is already fix.

        int n = heights.size();

        // For finding next smaller element.
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        // For -> previous smaller element
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        // Now we will check for maximum area
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            // if all the length are same
            // say 2 2 2 2
            // then in next and prev array
            // we will get all -1 -1 -1 -1
            // then breadth will be negative so to avoid that
            // case.
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int ar = l * b;
            area = max(ar, area);
        }
        return area;
    }
};