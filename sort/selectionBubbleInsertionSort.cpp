#include <bits/stdc++.h>
using namespace std;
void display(int v[], int n)
{

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
void selectionSort(int arr[], int n)
{
    // int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    bool alreadySorted = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                alreadySorted = false;
            }
        }
        if (alreadySorted)
            break;
    }
}
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
int main()
{
    int arr[6] = {2, 5, 1, 3, 6, 0};
    // cout << "Selection Sort" << endl;
    // selectionSort(arr, 6);

    // cout << "Bubble Sort" << endl;
    // bubbleSort(arr, 6);

    // cout << "Insertion Sort" << endl;
    // insertionSort(arr, 6);
    display(arr, 6);

    return 0;
}