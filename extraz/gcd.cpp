#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a > b)
        gcd(a - b, b);
    gcd(a, b - a);
}
int lcm(int a, int b)
{
    int hcf = gcd(a, b);
    return (a * b) / hcf;
}
int main()
{
    int hcf = gcd(9, 72);
    int lc = lcm(9, 72);
    cout << hcf << '\n';
    cout << lc << '\n';
    // a % n -> [0 -> n-1]
    return 0;
}