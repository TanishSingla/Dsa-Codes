#include <bits/stdc++.h>
using namespace std;

class overOp
{
public:
    int a;
    int add(int a, int b)
    {
        return a + b;
    }

    void operator+(overOp &obj)
    {
        int v1 = this->a;
        int v2 = obj.a;
        cout << "Output: " << v1 - v2 << '\n';
    }
};

int main()
{
    overOp o1, o2;
    o1.a = 9;
    o2.a = 10;
    o1 + o2;

    return 0;
}
/*


C++ also provides options to overload operators. For example, we can make the operator (‘+’) for
the string class to concatenate two strings. We know that this is the addition operator whose task is to add two operands.
A single operator, ‘+,’when placed between integer operands, adds them and concatenates
them when placed between string operands.

Points to remember while overloading an operator:-
1). It can be used only for user-defined operators(objects, structures) but
cannot be used for in-built operators(int, char, float, etc.)

2).Operators = and & are already overloaded in C++, so we can avoid overloading them

3).Precedence and associativity of operators remain intact.







*/