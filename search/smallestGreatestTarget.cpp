#include <bits/stdc++.h>
using namespace std;
int binarySearch(int n, int arr[], int key)
{
    int start = 0;
    int end = n - 1;
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
    return arr[start];
}
int main()
{
    //ceiling
    int arr[5] = {1, 3, 5, 7, 8};
    int target = binarySearch(5, arr, 4);
    cout << target << endl;

    return 0;
}