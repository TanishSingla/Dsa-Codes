#include <bits/stdc++.h>
using namespace std;
// printing all prime numbers from 0 -> n
void printPrime(int n)
{
    // Sieve of Eratosthenes...
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    /*
    Memset() is a C++ function. It copies a single character for a
    specified number of times to an object. It is defined in <cstring>
    header file.
    Syntax:
    void* memset( void* str, int ch, size_t n);

    Note: We can use memset() to set all values as 0 or -1 for integral data types also.
    It will not work if we use it to set as other values. The reason is simple, memset
    works byte by byte.

    */
    for (int i = 2; i * i < n; i++)
    {
        if (primes[i])
        {
            for (int j = 2 * i; j <= n; j *= i)
                primes[j] = false;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
            cout << i << " ";
    }
}

int squareRoot(int n)
{
    int start = 0;
    int end = n - 1;
    int middle = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (middle * middle == n)
            return middle;
        else if (middle * middle < n)
        {
            ans = middle;
            start = middle + 1;
        }
        else
            end = middle - 1;
        middle = start + (end - start) / 2;
    }
    return ans;
}
double morePrecision(double n, double precision, double tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{ // Sieve of Eratosthenes...
    // Time complexity -> N(log(log(N)))....
    // printPrime(n);
    // cout << '\n';
    int n;
    cin >> n;
    double sqr = squareRoot(n);
    double morePrecise = morePrecision(n, 5, sqr);
    cout << morePrecise << '\n';
    return 0;
}
