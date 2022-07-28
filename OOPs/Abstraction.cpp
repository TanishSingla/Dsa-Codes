#include <bits/stdc++.h>
using namespace std;

// Abstraction :- Abstraction means displaying only essential information and hiding the details
// Data abstraction refers to providing only necessary information about the outside world’s data, hiding
//  the background details or implementation. Let’s understand polymorphism with a real-life example.
// When you send an email to someone, you just click send, and you get the success message; what happens
// when you click send, how data is transmitted over the network to the recipient is hidden from you
// (because it is irrelevant to you).
class abstraction
{
private:
    int a, b;

public:
    // method to set values of private members
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
int main()
{
    abstraction obj;
    obj.set(10, 20);
    obj.display();

    return 0;
}