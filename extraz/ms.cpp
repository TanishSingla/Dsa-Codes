#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e, int mid)
{

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for (int i = s; i < e; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = s; i < e; i++)
    {
        second[i] = arr[k++];
    }

    // merge
    k = s;
    int i = 0;
    int j = 0;
    while (i < len1 && j < len2)
    {
        if (arr[i] <= arr[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = first[i++];
    }
    while (j < len2)
    {
        arr[k++] = second[j++];
    }
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    cout << "BOOM" << endl;
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}