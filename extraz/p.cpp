#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int num = 6;
    int *ptr = &num;
    cout << ptr << '\n';  //->give adress of num stored in ptr
    cout << *ptr << '\n'; //->give value of that variable whose adress is stored.
    cout << sizeof(ptr) << '\n';
    cout << sizeof(*ptr) << '\n';

    // how to intitalise after declaration.
    int *q;
    q = &num;
    cout << q << '\n';

    // copying pointer...
    int *copy = q;
    cout << copy << '\n';
    cout << *copy << '\n';

    // increament
    int inc = 3;
    int *in = &inc;
    cout << in << '\n';
    in = in + 1;
    cout << in << '\n';

    int arr[5] = {2, 9, 1, 5, 0};
    cout << arr << '\n'; // adress of first memory block
    cout << &arr[0] << '\n';
    cout << *arr << '\n'; // * -> Dereferencing operator -> it will give value of that var whose adress is stored
    // cout << sizeof(arr) << '\n';
    cout << *arr + 1 << '\n';
    cout << *(arr + 1) << endl; // arr+1 -> next location ..*(arr+1)->will guve next value

    // arr[i] = *(arr+i);
    // i[arr] = *(i+arr); -> this will nit give any error
    int *ptr = arr;
    cout << ptr << '\n';
    cout << *ptr << '\n';
    cout << &ptr << '\n';
    cout << sizeof(&ptr) << '\n';
    */
    // char ch[6] = "abcde";
    // cout << ch << '\n';
    // cout << *ch << '\n';
    // cout << &ch << '\n';
    // cout << &ch[0] << '\n';
    // cout << ch[3] << '\n';
    // function take array as a pointer

    /*Types of Pointers :-

        1. Null Pointers:
        A NULL pointer is a pointer that is pointing to nothing.
        If we don’t have the address to be assigned to a pointer, we can use NULL.

        Advantages of Null pointer are:
        (1) We can initialize a pointer variable when that pointer variable is not assigned any actual memory address.
        (2) We can pass a null pointer to a function argument when we are unwilling to pass any actual memory address.


        Example:
        int *p; //Contains garbage value
        int *p = NULL; //NULL is constant with vaue 0
        int *q = 0; // Same as above


        2. Double Pointers:
    We can create a pointer to a pointer that in turn may point to data or
    another pointer. The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double pointers.

    Example:
    int a = 10;
    int *p = &a;
    int **q = &p;
    Here q is a pointer to a pointer, i.e., a double-pointer, as indicated by **.


    3. Void Pointers:
    A void pointer is a generic pointer; it has no associated type with it.
    A void pointer can hold an address of any type and can be typecasted to any type. Thus we can use the void pointer to store the address of any variable.

    Void pointer is declared by:
    void *ptr;
    Note:
    1. void pointers cannot be dereferenced. It can, however, be done using typecasting the void pointer.
    2. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and size.

    Example :-
     void * ptr;
    int i = 10;
    // assign int address to void
    ptr = & i;
    */

    // Double pointer :- Pointer to  a pointer.
    int num = 6;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;
    cout << **ptr2 << '\n';
    cout << "*ptr2 -> Adress of ptr1 ->  " << *ptr2 << '\n';
    cout << "ptr1 -> Adress of ptr1 -> " << ptr1 << '\n';
    cout << "**ptr2 -> Value -> " << **ptr2 << '\n';
    cout << "ptr2 -> Adress  -> " << ptr2 << '\n';

    // Acessing value
    cout << endl;
    cout << "Acessing value" << '\n';
    cout << num << '\n';
    cout << *ptr1 << '\n';
    cout << **ptr2 << '\n';

    return 0;
}