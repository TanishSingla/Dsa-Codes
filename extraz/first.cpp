#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s)
{
    int st = 0;
    int e = s.size() - 1;
    while (st < e)
    {
        swap(s[st++], s[e--]);
    }
    int main()
    {
        char ch[20];
        cin >> ch;
        // suppose we store abc then at 3 index a null value will be stored.
        // so that we can know where our string ->end.
        // cin -> stop execution at space(" "), at tab(\t), at null char(\n)
        cout << ch << '\n';
        return 0;
    }

    // segmented seive
    // seieve of eratos
    // pigeonhole principal
    // catalon number
    // inclusive exclusive principle