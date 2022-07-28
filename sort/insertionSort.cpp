#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
            else
                break;
        }
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
int main()
{
    int arr[6] = {5, 3, 1, 7, 9, 4};
    insertionSort(arr, 6);
    display(arr, 6);

    return 0;
}
