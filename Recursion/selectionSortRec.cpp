#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n, int s)
{
    if (s >= (n - 1))
        return;
    int min = s;
    for (int i = s; i < n; i++)
    {
        if (arr[i] < arr[min])
            min = arr[i];
    }
    swap(arr[min], arr[s]);
    selectionSort(arr, n, s + 1);
}

void bubbleSortRecursion(int arr[], int n)
{
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSortRecursion(arr, n - 1);
}
int main()
{
    int arr[10] = {3, 4, 1, 2, 6, 7, 10, 9, 0, 8};
    selectionSort(arr, 10, 0);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}