#include <bits/stdc++.h>
int sqrtLinear(int x)
{
    //Time complexity-> root n
    long long int y = 0;
    while (y * y <= x)
        y++;
    return y - 1;
}
int sqrtBin(int x)
{

    //Time complexity -> O(logn)
    int s = 0;
    int e = x;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return mid - 1;
}
double morePrecise(int n, int p, int temp)
{
    double factor = 1;
    double ans = temp;
    for (int i = 0; i < p; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
using namespace std;
int main()
{
    cout << sqrtLinear(65) << endl;
    cout << sqrtBin(99) << endl;
    int t = sqrt(101);
    double mp = morePrecise(101, 4, 10);
    cout << mp << '\n';

    return 0;
}