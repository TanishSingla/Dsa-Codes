#include <iostream>
using namespace std;
void update1(int n)
{
    // pass By Value...
    n++;
}
void update2(int &n)
{
    // pass By Reference...
    n++;
}
int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    /*
    int i = 5;
    int &j = i; // ref var
    j++;
    cout << i << '\n';
    */
    // int n = 5;
    // cout << "Before " << n << '\n';
    // update2(n);
    // cout << "After " << n << '\n';

    // creating memory in heap...
    // memory created in stack->static memory->memory get released itself
    // memeory created in heap->dynamic memory->memory doesnt get released itself ..we release it using "delete" keyword
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // int sum = getSum(arr, n);
    // cout << sum << '\n';
    // delete[] arr;

    // int *a = new int;
    // *a = 5;
    // cout << a << '\n';

    int row;
    cin >> row;

    int col;
    cin >> col;

    // creating a 2D array
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // taking output
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    // how to create a 2D array dynamically
    // input/Output
    // memory free kaise karani hai
    // https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381146
    return 0;
}