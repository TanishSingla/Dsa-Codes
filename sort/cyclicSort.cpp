#include <bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int> &arr)
{
    // https://leetcode.com/problems/set-mismatch/submissions/
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            v.push_back(arr[i]);
            v.push_back(i + 1);
            break;
        }
    }
    return v;
}
vector<int> findDuplicates(vector<int> &arr)
{
    // https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
    vector<int> v;
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int correctIndex = arr[i] - 1;
        if (arr[i] != arr[correctIndex] && arr[i] != arr[correctIndex])
        {
            swap(arr[i], arr[correctIndex]);
        }
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            v.push_back(arr[i]);
    }
    return v;
}
int findDuplicate(vector<int> &arr)
{
    // https://leetcode.com/problems/find-the-duplicate-number/submissions/
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
            swap(arr[i], arr[correct]);
        else
            i++;
    }
    return arr[n - 1];
}
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    // https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
    vector<int> v;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct])
            swap(nums[i], nums[correct]);
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            v.push_back(i + 1);
    }
    return v;
}

int missingNumber(vector<int> &arr)
{
    // https://leetcode.com/problems/missing-number/submissions/
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        if (arr[i] < n && arr[i] != arr[arr[i]])
            swap(arr[i], arr[arr[i]]);
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
            return i;
    }
    return n;
}
void cyclicSort(int arr[], int n)
{
    // 0 1 2 3 4
    // 5 3 1 2 4
    // 1 2 3 4 5
    int i = 0;
    while (i < n)
    {
        int correctIndex = arr[i] - 1;
        if (arr[i] != arr[correctIndex])
            swap(arr[i], arr[correctIndex]);
        else
            i++;
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    // wherever we see 1 to N -> Use Cyclic Sort.
    // Time complexity -> O(n)
    int arr[5] = {5, 4, 3, 2, 1};
    cyclicSort(arr, 5);
    display(arr, 5);

    return 0;
}