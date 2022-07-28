#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];
    int cnt = 0;

    for (int i = s + 1; i < e; i++)
    {
        if (pivot > arr[i])
            cnt++;
    }
    int rightIndex = cnt + s;
    swap(arr[s], arr[rightIndex]);

    // left -> small....right->big
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

    int p = partition(arr, s, e);

    // first Part
    quickSort(arr, s, p);

    // second part
    quickSort(arr, p + 1, e);
}

// Merge Sort

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int mainIndex = s;
    int *first = new int[len1];
    int *second = new int[len2];
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }

    // merge..
    int i = 0;
    int j = 0;
    mainIndex = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[mainIndex++] = first[i++];
        }
        else
            arr[mainIndex++] = second[j++];
    }
    while (i < len1)
    {
        arr[mainIndex++] = first[i++];
    }
    while (j < len2)
    {
        arr[mainIndex++] = second[j++];
    }
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[7] = {5, 4, 3, 2, 1, 0, 11};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}