#include <bits/stdc++.h>
using namespace std;

bool arraySorted(int arr[], int n)
{
    if (n < 2)
        return true;
    if (arr[n - 1] < arr[n - 2])
        return false;
    arraySorted(arr, n - 1);
}
bool arraySorted2(int *arr, int n)
{
    if (n == 0 || n == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    else
        return arraySorted2(arr + 1, n - 1);
}
int sum(int *arr, int n)
{
    if (n <= 0)
        return 0;
    return (sum(arr, n - 1) + arr[n - 1]);
}
int linearSearch(int *arr, int n, int target, int index)
{
    if (index == n)
        return -1;
    if (arr[index] == target)
        return index;
    return linearSearch(arr, n, target, index + 1);
}
int rotatedBinarySearchRecursion(int *arr, int target, int s, int e)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[s] <= arr[mid])
    {
        if (target >= arr[s] && target <= arr[mid])
        {
            return rotatedBinarySearchRecursion(arr, target, s, mid - 1);
        }
        else
        {
            return rotatedBinarySearchRecursion(arr, target, mid + 1, e);
        }
    }
    if (target >= arr[mid] && target <= arr[e])
    {
        return rotatedBinarySearchRecursion(arr, target, mid + 1, e);
    }

    return rotatedBinarySearchRecursion(arr, target, s, mid - 1);
}
int main()
{
    int arr[10] = {5, 6, 7, 8, 9, 10, 11, 1, 2, 3};
    int ans = rotatedBinarySearchRecursion(arr, 1, 0, 10);
    cout << ans << '\n';
    // int ans = linearSearch(arr, 8, 11, 0);
    // cout << ans << '\n';
    // int ans = sum(arr, 5);
    // cout << ans << '\n';

    return 0;
}