#include <bits/stdc++.h>
using namespace std;
// Encapsulation :- The process of grouping data members and corresponding methods into a single unit.
// We can create a fully encapsulated class by making all the data members private. If the data members
// are private, it can only be accessible within the class; no other class can access that class’s data members.
// we can say that encapsulation is used for data hiding.
// In Encapsulation, we can hide the data’s internal information, which is better for security concerns.
// Encapsulated code is better for unit testing.

// Inheritance :- Inheritance is the process of inheriting the properties and behavior of an existing
// class into a new class. When we inherit the class, we can reuse the existing class’s methods and
// fields into a new class.
// Inheritance is a parent-child relationship
// Advantage of using Inheritance:-
// Code reussability
// Syntax for making a child class inheriting from parent class
// class child_class: access_modifier parent_class {........}
class human
{
    string blood;
    int age;
    int height;

public:
    int getAge()
    {
        return age;
    }
    int setAge(int age)
    {
        this->age = age;
    }

protected:
    int shoeSize;
};

class male : public human
{
    // human class(super/parent class) -> male class -> child class
    // as we are inheriting male class from human class publically
    // so
    // Parent class    Child class
    // public           public     ->   public
    // public           private     ->  private
    // public           protected     ->   protected
public:
    void ShortHair()
    {
        cout << "Male with Short Hairs";
    }
};

class female : protected human
{
    // Parent class    Child class
    // protected         public    ->   protected
    // protected         protected ->   protected
    // protected         private   ->  private
public:
    void hairColor()
    {
        cout << "Women with long hairs " << '\n';
    }
};
class male2 : private human
{
    // private  private     NA
    // private  public      NA
    // private  protected   NA

    // private datamember of any class can not be inherited .
};
int main()
{
    // Encapsulation
    human h1;
    h1.setAge(8);
    cout << h1.getAge() << endl;

    // Inheritance
    male m1;
    cout << m1.getAge() << '\n';

    // female f1;
    // cout << f1.getAge() << endl;

    return 0;
}