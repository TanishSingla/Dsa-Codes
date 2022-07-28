#include <bits/stdc++.h>
using namespace std;
int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
        mid = s + (e - s) / 2;
    }
    return s;
}

int getPivot2(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid < e && arr[mid] > arr[mid + 1])
            return mid;
        if (s < mid && arr[mid] < arr[mid - 1])
            return mid - 1;
        if (arr[mid] <= arr[s])
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[5] = {2, 9, 2, 2, 2};
    int ans = getPivot(arr, 5);
    int maxi = 0;
    for (int i = 0; i < 5; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    // cout << ans;
    cout << maxi;

    return 0;
}