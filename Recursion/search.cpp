#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int target)
{
    if (arr[n - 1] == target)
        return n - 1;
    if (n < 0)
        return -1;
    return search(arr, n - 1, target);
}
int main()
{
    int arr[5] = {6, 9, 0, 1, 3};
    int index = search(arr, 5, 0);
    cout << index << '\n';

    return 0;
}