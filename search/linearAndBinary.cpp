#include <bits/stdc++.h>
using namespace std;
int linearSearch(int n, int arr[], int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    //time complexity O(n)
}

int binarySearch(int n, int arr[], int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    //mid-> start + (end-start)/2 is same as writing (start+end)/2
    //we did this becoz,suppose we have start and end very big numbers
    // then we cant add them so thats why wwe use this little trick...

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
    //time complexity :- as our array is getting divide by 2 everytime
    //suppose we have an array of 1000 size then there will be
    //total 10 comparison to find an element(worst case)
    //1000/2=500 , 500/2=250, 250/2=125, 125/2=62, 62/2=31, 31/2=15, 15/2=7, 7/2=3, 3/2=1, 1/2=0
    //so its time complexity will be O(logn)....
}
int main()
{
    int ar[6] = {1, 2, 4, 6, 9, 11};
    // sort(ar, ar + 6);
    int index = binarySearch(6, ar, 6);
    cout << index << endl;

    return 0;
}