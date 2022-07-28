#include <iostream>
using namespace std;
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    // cnt -> for checking how many elements are less than pivot
    int cnt = 0;
    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    // right index for pivot element is...
    int rightIndex = s + cnt;
    swap(arr[s], arr[rightIndex]);

    // now we will check-> that all elements from pivot to its left are less
    // and in right are greater than pivot or not..

    int i = s;
    // i -> left pointer
    int j = e;
    // j -> right pointer
    while (i < rightIndex && j > rightIndex)
    {
        while (arr[i] <= arr[rightIndex])
        {
            i++;
        }
        while (arr[j] >= arr[rightIndex])
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
    // base condition....
    if (s >= e)
        return;
    int index = partition(arr, s, e);

    // for first part...
    quickSort(arr, s, index);

    // for second part..
    quickSort(arr, index + 1, e);
}

int main()
{
    int arr[6] = {4, 2, 5, 1, 3, 0};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";

    return 0;
}