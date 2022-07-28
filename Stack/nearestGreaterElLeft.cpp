#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{2, 3, 1, 2, 5};
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++)
    {

        while (s.top() != -1 && s.top() <= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
