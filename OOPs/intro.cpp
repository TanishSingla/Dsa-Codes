#include <bits/stdc++.h>
using namespace std;
class Hero
{
public:
    int health;
    int level;
    char c;
    char *name;
    // creating static variable :- belongs to class not to object.
    static int timeToComplete;

    // static function :- can acces only static memeber
    // no need to create object
    // dnt have this keyword as this is pointer to current object.
    static int random()
    {
        cout << "Static Function " << '\n';
        return timeToComplete;
    }

    // Constructor
    Hero()
    {
        name = new char[100];
        cout << "Constrcutor Called" << endl;
    }
    // Parametrised constructor ;-
    Hero(int health)
    {
        cout << this << '\n';
        this->health = health;
        // this keyword :- it is a pointer to the current object.
        // this stores current object adress.
    }
    Hero(int health, int level)
    {
        this->health = health;
        this->level = level;
    }
    // copy constructor :- Creating our own copy constructor.
    // and also when we create our own copy contsructor
    // defalut copy constructor get automatically deleted.
    Hero(Hero &temp)
    {
        this->health = temp.health;
        this->c = temp.c;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        // not using & ->  will give error
        //  as we are calling it by pass by value ...and as we know
        //  in pass by value it will make a copy and for making
        //  copy it will call copy constructor
        //  and we will stuck in this loop..
        //  so to avoid this we use pass by reference.
    }
    void print()
    {
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
        cout << "Name: " << name << endl;
    }

private:
    int age;

public:
    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
    ~Hero()
    {
        cout << "Destructor called " << '\n';
    }
};

int Hero::timeToComplete = 6;

int main()
{

    cout << Hero::timeToComplete << '\n';

    /*
    Hero paul;
    // here we have created a paul var of hero data type having health and level as its property.
    cout << sizeof(Hero) << endl;
    // health (4 bit),level( 4bit), char(1 bit) -> Total 9 bit
    // output 12 bit -> strcuture padding
    paul.health = 10;
    paul.level = 70;
    // cout << paul.health;
    */

    // get and set function -> to acees private member of  class

    /*
        Hero adam;
        adam.setAge(10);
        cout << adam.getAge() << endl;

        // creating object dynamically :-
        Hero *maxim = new Hero();
        (*maxim).health = 20;
        cout << maxim->health << endl;
        cout << (*maxim).health << '\n';
    */

    // constructor :- In C++, Constructor is automatically called when object(instance of class) is
    // created. It is special member function of the class because it does not have any return type.
    // Constructor has same name as the class itself
    // Constructors don’t have input argument
    // Constructors don’t have return type
    // A constructor is automatically called when an object is created.
    // It must be placed in public section of class.
    // If we do not specify a constructor, C++ compiler generates a
    // default constructor for object (expects no parameters and has an empty body).

    // if we create any constructor the default constructor get automatically deleted.

    /*
    Hero Boom; // by default there is a constructor.
    Hero *a = new Hero;
    (*a).print();
    a->print();

    // Parametrised Constructor :-
    Hero Maxim(10);
    cout << &Maxim << '\n';
    // adress of this and Maxim will be same
    // as this will point to current object.

    // Note :- whenever we create a constructor the edefault constructor
    // get automatically deleted.

    // Copy Constructor :-
    // A copy constructor is a member function that initializes an object using another
    // object of the same class.A copy constructor has the following general function prototype :
    // ClassName(const ClassName &old_obj);
    // If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor
    // for each class which does a
    // member-wise copy between objects. The compiler created copy constructor works fine in general.

    cout << " Copy Constructor " << endl;
    Hero C(100);
    // C.name = "Boom";
    C.print();
    // calling copy constructor :-
    Hero copy(C);
    copy.print();
    // default copy constructor follows shallow copy
    // means there is single memory and the copy object is pointing to same memory
    // so if we change anything in first object it will be change in second object also.

    // the copy constructor we created follows deep copy
    // i.e deep copy constructor. and there will be another memory for that
    // object. so if we change anything in first that doesnt affect other one
    // as they both beloons to different memory location.

    // assignment operator
    cout << '\n';
    cout << '\n';
    Hero h1(100, 10);
    h1.print();
    Hero h2(200, 20);
    h2.print();
    h2 = h1;
    h2.print();
    cout << "jhdcw" << '\n';
    */

    // desctructor :- Destructor is an instance member
    // function which is invoked automatically whenever an object is going to be destroyed. Meaning, a
    // destructor is the last function that is going to be called before an object is destroyed.
    // Destructor is used to free memory..(to deallocate memory)
    // destructor -> same name as class name
    //           -> no return type
    //           -> no parameter
    // we can create our own destructor also.

    // static
    Hero a;
    // for static allocation destructor get automatically called

    // dynamically
    Hero *b = new Hero;
    // but for dynamic location -> we have to call destructor manually.
    // so we use delete
    delete b;
    // as constructor is called only once for a object at time of executuion
    // as same goes for destructor it will also called once at time of destruction.
    // and also default destructor will be deleted automatically.

    return 0;

    // Padding
    // Greedy alignment
    // const keyword and const function
    // initialisation list
}