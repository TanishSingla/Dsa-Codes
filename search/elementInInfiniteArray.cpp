#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int start, int end)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int range(int arr[], int key)
{
    int s = 0;
    int e = 1;
    int mid = s + (e - s) / 2;
    while (key > arr[e])
    {
        int newStart = e + 1;
        e = e + (e - s + 1) * 2;
        s = newStart;
    }
    return binarySearch(arr, key, s, e);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 11, 14, 16, 19};
    int key = 11;
    int ans = range(arr, key);
    cout << ans << endl;
    return 0;
}