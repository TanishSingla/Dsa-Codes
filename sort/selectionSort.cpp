#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{

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
void bubbleSort(vector<int> &arr, int n)
{
    bool alreadySorted = true;
    // Write your code here.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int main()
{
    // for selection Sort ;-
    //  Time complexity-> O(n2)
    // worst and best case O(n2)
    int arr[6] = {2, 5, 1, 3, 6, 0};
    for (int k = 0; k < 6; k++)
    {
        cout << arr[k] << " ";
    }
    SelectionSort(arr, 6);
    cout << endl;
    for (int k = 0; k < 6; k++)
    {
        cout << arr[k] << " ";
    }

    // Bubble Sort :-
    // Time complexity :-
    // best case -> O(n)
    // worst case -> O(n2)

    return 0;
}