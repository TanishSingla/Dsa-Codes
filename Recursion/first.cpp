#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    int hcf = gcd(a, b);
    return (a * b) / hcf;
}
int fibByFormula(int n)
{
    return pow((1 + sqrt(5)) / 2, n) / sqrt(5);
}
int fib(int n)
{
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int normalBinarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int middle = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[middle] == target)
            return middle;
        if (target > arr[middle])
            start = middle + 1;
        else
            end = middle - 1;
        middle = start + (end - start) / 2;
    }
    return -1;
}
int recursiveBinarySearch(int arr[], int n, int s, int e, int target)
{
    if (s > e)
        return -1;
    int middle = s + (e - s) / 2;
    if (arr[middle] == target)
        return middle;
    if (arr[middle] > target)
        return recursiveBinarySearch(arr, n, s, middle - 1, target);

    return recursiveBinarySearch(arr, n, middle + 1, e, target);
}
int main()
{

    // Recursion...
    // int ans = fib(4);
    // cout << ans << '\n';

    // int arr[5] = {1, 2, 3, 4, 5};
    // // int ans = normalBinarySearch(arr, 5, 4);
    // int ans = recursiveBinarySearch(arr, 5, 0, 4, 5);
    // cout << ans << '\n';

    // int ans = fibByFormula(10);
    // cout << ans << '\n';
    // int hcf = gcd(4, 8);
    // cout << "HCF " << hcf << '\n';
    // int l = lcm(4, 7);
    // cout << "LCM " << l << '\n';
    int f = fibByFormula(3);
    cout << f << '\n';

    return 0;
}