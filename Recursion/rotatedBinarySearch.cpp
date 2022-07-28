#include <bits/stdc++.h>
using namespace std;
int rotatedBinarySearch(int arr[], int n, int key, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s > e)
        return -1;
    if (arr[mid] == key)
        return mid;
    if (arr[s] <= arr[mid])
    {
        if (key >= arr[s] && key <= arr[mid])
            return rotatedBinarySearch(arr, n, key, s, mid - 1);
        else
            return rotatedBinarySearch(arr, n, key, mid + 1, e);
    }
    if (key >= arr[mid] && key <= arr[e])
        return rotatedBinarySearch(arr, n, key, mid + 1, e);
    else
        return rotatedBinarySearch(arr, n, key, s, mid - 1);
}
int main()
{
    int arr[8] = {5, 6, 7, 8, 9, 1, 2, 3};
    int ans = rotatedBinarySearch(arr, 8, , 0, 7);
    cout << ans << '\n';

    return 0;
}