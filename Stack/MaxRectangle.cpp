// https://practice.geeksforgeeks.org/problems/max-rectangle/1/
// T.C -> O(n x m)
// S.C -> O(m)
class Solution
{

private:
    vector<int> nextSmaller(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

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
    vector<int> prevSmaller(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

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

    int largestArea(int *arr, int n)
    {
        vector<int> next(n);
        next = nextSmaller(arr, n);
        vector<int> prev(n);
        prev = prevSmaller(arr, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = arr[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int tempAr = l * b;
            area = max(area, tempAr);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here

        // first we will find area for first row
        int area = largestArea(M[0], m);

        // for remaining rows :-
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            // now we will check area of that updated row
            area = max(area, largestArea(M[i], m));
        }
        return area;
    }
};