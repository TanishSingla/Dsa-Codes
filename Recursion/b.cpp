#include <bits/stdc++.h>
using namespace std;
void fun1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    fun1(n - 1);
}
void fun2(int n)
{
    if (n == 0)
        return;
    fun2(n - 1);
    cout << n << " ";
}
void fun3(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    fun3(n - 1);
    cout << n << " ";
}
int factorial(int n)
{
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}
int sumOfDigits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int sumOfDigitsRecursion(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigitsRecursion(n / 10);
}
int reverse(int n)
{
    static int rev = 0;
    if (n == 0)
        return rev;
    rev = rev * 10 + (n % 10);
    return reverse(n / 10);
}
/*
int countNumberOfZeros(int n)
{
    return helper(n, 0);
}

int helper(int n, int c)
{
    if (n == 0)
        return c;
    int rem = n % 10;
    if (rem == 0)
        return helper(n / 10, c + 1);
    return helper(n / 10, c);
}
*/
int main()
{
    /*
    fun1(5);
    cout << '\n';
    fun2(5);
    cout << endl;
    fun3(5);
    */
    int fact = factorial(5);
    cout << fact << '\n';
    int sum = sumOfDigitsRecursion(123456);
    cout << sum << endl;
    int rev = reverse(1234);
    cout << rev << '\n';
    int c = 0;

    return 0;
}