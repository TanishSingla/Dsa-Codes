#include <bits/stdc++.h>
using namespace std;
int xorz(int n)
{
    // from 0 to n
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    return 0;
}
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
int power(int n, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1 == 1)
            ans *= n;
        n *= n;
        p = p >> 1;
    }
    return ans;
}
bool powerOfTwo(int n)
{
    return !(n & (n - 1));
}
int numberOfDigits(int n, int base)
{
    return (int)(log(n) / log(base)) + 1;
}
int magicNumber(int n)
{
    int ans = 0;
    int base = 5;
    while (n > 0)
    {
        int last = n & 1;
        n = n >> 1;
        ans += last * base;
        base = base * 5;
    }
    return ans;
}
int findingiBit(int n, int y)
{
    return n & (1 << (y - 1));
}
int notDuplicate(int arr[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c ^= arr[i];
    }
    return c;
}
bool isEven(int n)
{
    return !(n & 1);
}
int main()
{
    int n;
    cin >> n;
    /*
    if (isEven(n))
        cout << n << " is Even " << '\n';
    else
        cout << n << " is odd" << '\n';
    int arr[5] = {1, 1, 2, 2, 3};
    int que1 = notDuplicate(arr, 5);
    cout << que1 << '\n';

    // i bit
    int x, y;
    cin >> x >> y;
    int ithBit = findingiBit(x, y);
    cout << ithBit << '\n';
    */
    int magicNum = magicNumber(n);
    cout << "Magic Number " << magicNum << '\n';
    int numofDigits = numberOfDigits(10, 2);
    cout << "  Number of Digits " << numofDigits << '\n';
    int poweroftwo = powerOfTwo(n);
    cout << "    Power of Two? " << poweroftwo << '\n';
    int powerz = power(2, 8);
    cout << "      Power " << powerz << '\n';
    int numOfSetBits = countSetBits(n);
    cout << "        Number of set Bits " << numOfSetBits << '\n';
    int x = xorz(8);
    cout << "          XOR from 0 to 8 is " << x << '\n';
    return 0;
}