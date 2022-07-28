#include <bits/stdc++.h>
using namespace std;
int bs_rec(int *arr, int n, int key, int s, int e)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return bs_rec(arr, n, key, s, mid - 1);
    return bs_rec(arr, n, key, mid + 1, e);
}
int main()
{
    int arr[6] = {1, 3, 4, 6, 7, 9};
    int ans = bs_rec(arr, 6, 11, 0, 6);
    cout << ans << '\n';

    return 0;
}