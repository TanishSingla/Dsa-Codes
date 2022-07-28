#include <bits/stdc++.h>
using namespace std;
// 1.)
// static int sum = 0;
// int fun1(int n)
// {
//     if (n == 0)
//         return sum;
//     int rem = n % 10;
//     sum = sum * 10 + rem;
//     fun1(n / 10);
// }

// 2.)
int helper(int n, int digit)
{
    if (n % 10 == n)
        return n;
    int rem = n % 10;
    return rem * pow(10, digit) + helper(n / 10, digit - 1);
}
int fun2(int n)
{
    int digit = (int)log10(n);
    return helper(n, digit);
}

// Number of zeros
static int c = 0;
int numberOFzeero(int n)
{
    if (n == 0)
        return c;
    int rem = n % 10;
    if (rem == 0)
        c++;
    numberOFzeero(n / 10);
}

int main()
{
    // 1923->  3 + Reverse(192) -> 2 + Reverse(19)....
    int rev1 = numberOFzeero(10003);
    cout << rev1 << '\n';

    return 0;
}