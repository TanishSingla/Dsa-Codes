#include <iostream>
using namespace std;
void mergeTwoSortedArrays(int arr1[], int a1, int arr2[], int a2, int arr3[], int a3)
{
    int i = 0, j = 0;
    int k = 0;
    while (i < a1 && j < a2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (j < a2)
        arr3[k++] = arr2[j++];
}
int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 11};
    int arr3[8] = {0};
    mergeTwoSortedArrays(arr1, 5, arr2, 3, arr3, 8);
    for (int i = 0; i < 8; i++)
        cout << arr3[i] << " ";
    return 0;
}