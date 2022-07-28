//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
int getPivot2(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid < e && arr[mid] > arr[mid + 1])
            return mid;
        if (s < mid && arr[mid] < arr[mid - 1])
            return mid - 1;
        if (arr[mid] <= arr[s])
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return -1;
}
int binarySearch(vector<int> &arr, int key, int start, int end)
{
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        int n = arr.size();
        int pivot = getPivot2(arr, n);
        if (pivot == -1)
        {
            return binarySearch(arr, key, 0, n - 1);
        }
        if (arr[pivot] == key)
            return pivot;
        if (key >= arr[0])
            return binarySearch(arr, key, 0, pivot - 1);
        return binarySearch(arr, key, pivot + 1, n - 1);
    }
};