/*
#include <iostream>
using namespace std;
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
            count++;
    }
    int rightIndex = count + s;
    swap(arr[rightIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < rightIndex && j > rightIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < rightIndex && j > rightIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return rightIndex;
}
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int p = partition(arr, s, e);

    // first part
    quickSort(arr, s, p - 1);

    // second Part
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[8] = {5, 5, 5, 4, 3, 2, 1, 0};
    quickSort(arr, 0, 7);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
            cnt++;
    }
    int rightIndex = s + cnt;
    swap(arr[rightIndex], arr[s]);
    int i = s;
    int j = e;
    while (i < rightIndex && j > rightIndex)
    {
        while (arr[i] <= arr[rightIndex])
            i++;
        while (arr[j] > arr[rightIndex])
            j--;
        if (i < rightIndex && j > rightIndex)
            swap(arr[i++], arr[j--]);
    }
    return rightIndex;
}
void quickSort(int *arr, int s, int e)
{

    if (s >= e)
        return;
    int index = partition(arr, s, e);
    quickSort(arr, s, index);
    quickSort(arr, index + 1, e);
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}