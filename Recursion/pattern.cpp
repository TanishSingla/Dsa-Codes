#include <bits/stdc++.h>
using namespace std;
void usingLoop(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}
void usingRecursion(int r, int c)
{
    if (r == 0)
        return;
    if (c < r)
    {
        cout << "*"
             << " ";
        usingRecursion(r, c + 1);
    }
    else
    {
        cout << endl;
        usingRecursion(r - 1, 0);
    }
}
void usingRecursion2(int r, int c)
{
    if (r == 0)
        return;
    if (c < r)
    {
        usingRecursion2(r, c + 1);
        cout << "*"
             << " ";
    }
    else
    {
        usingRecursion2(r - 1, 0);
        cout << endl;
    }
}
int main()
{
    usingLoop(4);
    // cout << endl;
    usingRecursion2(4, 0);
    return 0;
}