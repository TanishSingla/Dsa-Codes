#include <bits/stdc++.h>
using namespace std;
int firstOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int LastOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[5] = {1, 2, 3, 3, 5};
    int leftOccurence = firstOccurence(arr, 5, 3);
    int RightOccurence = LastOccurence(arr, 5, 3);
    cout << "First occurence of 3 is at index  " << leftOccurence << endl;
    cout << "Last occurence of 3 is at index  " << RightOccurence << endl;
    //to find total number of occurences
    cout << "Number of times 3 is occuring " << RightOccurence - leftOccurence + 1 << endl;

    return 0;
}