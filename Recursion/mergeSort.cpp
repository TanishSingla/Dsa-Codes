#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int mainArrayIndex = s;
    int *first = new int[len1];
    int *second = new int[len2];
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int i = 0;
    int j = 0;
    mainArrayIndex = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[mainArrayIndex++] = first[i++];
        }
        else
        {
            arr[mainArrayIndex++] = second[j++];
        }
    }
    while (i < len1)
    {
        arr[mainArrayIndex++] = first[i++];
    }
    while (j < len2)
    {
        arr[mainArrayIndex++] = second[j++];
    }
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};

    mergeSort(arr, 0, 14);

    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}