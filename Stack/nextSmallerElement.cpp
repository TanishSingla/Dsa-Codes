#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {

        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
// https://afteracademy.com/blog/largest-rectangle-in-a-histogram
//  O(N) -> T.C
/*
2 1 4 3
3 -> -1
s.push(3);

4->3
3<4
s.push(4);

1-> -1
1<4
s.push(1);

2->1
1<2
s.push(2)


*/