#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void fun() { cout << "A" << '\n'; }
};
class B
{
public:
    void fun() { cout << "B" << '\n'; }
};
class C : public A, public B
{
};
int main()
{
    C ob1;
    ob1.A::fun();
    ob1.B::fun();

    return 0;
}

/*
C++ Ambiguity:-
There may be a possibility that a class may inherit member
functions with the same name from two or more base classes,
and the derived class may not have functions with the same
name as those of its base classes. If the derived class object
needs to access one of the same-named member functions of the base
classes, it results in ambiguity as it is not clear to the compiler
 which base’s class member function should be invoked.
*/