#include <bits/stdc++.h>
using namespace std;

class birds
{
public:
    void speak()
    {
        cout << "Chirruping" << '\n';
    }
};
class animal
{
public:
    void bark()
    {
        cout << "Barking" << '\n';
    }
};
// Muiltiple Inheritance
class mixBread : public birds, public animal
{
};

int main()
{
    mixBread h1;
    h1.bark();
    h1.speak();

    return 0;
}