#include <bits/stdc++.h>
using namespace std;
// creating macro
#define PI 3.14
// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

inline int getSum(int &a, int &b)
{
    // inline function works for 1 or 2 line code only....
    // inline function are good to use..becoz at code running time they replace that code
    // and doesnt require function call in stack.

    return a + b;
}
int main()
{
    int r = 10;
    double area = PI * r * r;
    cout << area << '\n';

    // inline function...
    int a = 5;
    int b = 10;
    int ans = getSum(a, b);
    cout << ans << '\n';

    return 0;
}