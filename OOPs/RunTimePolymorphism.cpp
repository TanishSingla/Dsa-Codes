#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    void print()
    {
        cout << "Class A" << '\n';
    }
};
class B : public A
{
public:
    void print()
    {
        cout << "Class B" << '\n';
    }
};
int main()
{
    // Run-Time polymorphism depends on Inheritance
    // means RUN-TIME-POLYMORPHISM can be achieved
    // only throught Inheritance.

    // Rules for method overriding:
    // The method of the parent class and the method of the child class must have the same name.
    // The method of the parent class and the method of the child class must have the same parameters.
    // It is possible through inheritance only.

    B obB;
    obB.print();

    return 0;
}