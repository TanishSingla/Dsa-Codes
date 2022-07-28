#include <bits/stdc++.h>
using namespace std;
void helper(string &s, int st, int e)
{
    if (st > e)
        return;
    swap(s[st++], s[e--]);
    helper(s, st, e);
}
void rev(string &s)
{
    int l = s.length() - 1;
    helper(s, 0, l);
}

bool helper2(string s, int st, int end)
{
    if (st > end)
        return true;
    if (s[st++] != s[end--])
        return false;
    return helper2(s, st, end);
}
bool pallindrome(string s)
{
    int l = s.length() - 1;
    return helper2(s, 0, l);
}
int pow_rec(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        return pow_rec(a * a, b / 2);
    }
    return a * pow_rec(a * a, b / 2);
}
int main()
{
    string s = "TANISH";
    rev(s);
    cout << s << '\n';
    string p = "abcba";
    bool ans = pallindrome(p);
    cout << ans << '\n';

    int power = pow_rec(2, 4);
    cout << power << '\n';
    return 0;
}