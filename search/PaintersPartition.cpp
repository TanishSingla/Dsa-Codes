#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, int mid)
{
    int n = arr.size();
    int sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + sum <= mid)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            if (count > k || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &arr, int k)
{

    //k->no of painters
    int n = arr.size();
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, k, mid))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    return 0;
}