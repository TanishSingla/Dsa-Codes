#include <bits/stdc++.h>
using namespace std;
int a(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    int x = a(n - 1);
    int y = a(n - 2);
    return x + y;
}
int main()
{
    // int a, b;
    // cin >> a >> b;
    // if we do modulo of any number then -> it will be from 0 to modulo - 1.
    // if we have a negative number say -5 ,-5 % 3 == -2, so in this case
    // we do ((a%m)+m) % m
    // 1).(a+b) % m = [(a % m) + (b % m)] % m
    // 2).(a-b) % m = [((a % m) - (b % m)) + m] % m
    // 3).(a*b) % m = [(a % m) * (b % m)] % m
    // 4).(a/b) % m = [(a % m) * (b pow(-1) % m)] % m
    // 5).(a % m) % m = a % m
    // m pow(x) % m = 0
    // cout << (a + b) % 2 << '\n';
    // cout << ((a % 2) + (b % 2)) % 2 << '\n';
    int ans = a(5);
    cout << ans;
    return 0;
}