#include <bits/stdc++.h>
using namespace std;
vector<int> findTarget(int arr[], int n, int target, vector<int> arr2, int index)
{
    if (index == n)
        return arr2;
    if (arr[index] == target)
        arr2.push_back(index);
    return findTarget(arr, n, target, arr2, index + 1);
}
int main()
{
    vector<int> ans;
    int arr[5] = {1, 2, 4, 4, 5};
    int n = 5;
    findTarget(arr, n, 4, ans, 0);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}