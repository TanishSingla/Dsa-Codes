// #include <bits/stdc++.h>
// using namespace std;
// int getPivot(int arr[], int n)
// {
//     int s = 0, e = n - 1;
//     int mid = s + (e - s) / 2;
//     while (s < e)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return s;
// }
// int binarySearch(int arr[], int st, int en, int key)
// {
//     int s = st;
//     int e = en;
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == key)
//             return mid;
//         else if (arr[mid] > key)
//             e = mid - 1;
//         else
//             s = mid + 1;

//         mid = s + (e - s) / 2;
//     }
//     return -1;
// }
// int search(int *arr, int n, int key)
// {
//     // Write your code here.
//     int pivot = getPivot(arr, n);
//     if (key >= arr[pivot] && key <= arr[n - 1])
//     {
//         return binarySearch(arr, pivot, n - 1, key);
//     }
//     else
//     {
//         return binarySearch(arr, 0, pivot - 1, key);
//     }
// }
// int main()
// {
//     int arr[5] = {5, 1, 2, 3, 4};
//     int ans = search(arr, 5, 3);
//     cout << ans;
//     return 0;
// }

//Book Allocation :-
bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studetCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + pageSum <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studetCount++;
            if (studetCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return mid;
}

int main()
{

    return 0;
}