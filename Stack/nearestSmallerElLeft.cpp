#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElLeft(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (s.top() >= arr[i])
            s.pop();

        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr{5, 1, 2, 6, 0, 6, 4, 2, 8, 9, 1};
    int n = arr.size();
    vector<int> ans(n);
    ans = nearestSmallerElLeft(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}