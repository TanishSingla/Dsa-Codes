#include <bits/stdc++.h>
using namespace std;

// a) Function overloading:
// When there are multiple functions in a class with the same
// name but different parameters, these functions are overloaded.
// The main advantage of function overloading is it increases the
// readability of the program.Functions can be overloaded by using
// different numbers of arguments and by using different types of arguments.

class A
{
public:
    void print1()
    {
        cout << "Void function with 0 paramter" << '\n';
    }
    void print1(int n)
    {
        cout << "Void function with 1 parameter " << n << '\n';
    }

    /*
    //this can not be overlaoded
        int print1()
        {
            return 1;
        }
    */
};

int add(int a, int b, int c = 0)
{
    return a + b;
}
int add(auto a, auto b)
{
    cout << "auto" << '\n';
    return a + b;
}
// int add(int a, int b, int c)
// {
//     return a + b + c;
// }
// double add(int a, double b)
{
    return a + b;
}

int main()
{
    A ob1;
    ob1.print1();
    cout << add(20.3, 30.3) << endl;

    return 0;
}