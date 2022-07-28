#include <bits/stdc++.h>
using namespace std;
/*
int numberOfWays(int n)
{
    // que -> a person can move atomost at 3 stairs..
    // we have to tell number of ways he can reach its destination.
    if (n == 1) // in 1 stair -> 1 way
        return 1;
    if (n == 2) // 2 stair -> can go by 2 ways i.e 1...1 and directly at 2
        return 2;
    if (n == 3) // 3 stair -> can go by 4 ways ...a)1 by 1 (b)2...1 (c)1....2 (d)directly at 3
        return 4;
    return numberOfWays(n - 1) + numberOfWays(n - 2) + numberOfWays(n - 3);
}
*/
int waysToReachBottom(int row, int col, string output[])
{
    // All possible paths -> in matrix we have to tell number of
    // ways to reach from top left to right bottm i,e from (0,0) to (n-1,n-1)
    // and person can travel only horizonrtally('H') and vertically('V')
    // recursively ->
    //  ways(row,col) = ways(row-1,col)+ 'H'  + ways(row,col-1) + 'V'

    // making temp array
    string temp[1000];
    int k = 0;
    // base case
    if (row == 1)
    {
        for (int i = 0; i < col - 1; i++)
        {
            output[i] = 'H';
        }
        return 1;
    }
    if (col == 1)
    {
        for (int i = 0; i < row - 1; i++)
        {
            output[i] = 'V';
        }
        return 1;
    }

    // ways(row,col) = ways(row-1,col)+ 'H'  + ways(row,col-1) + 'V'
    int smallerOutput1Size = waysToReachBottom(row - 1, col, output);
    for (int i = 0; i < smallerOutput1Size; i++)
    {
        temp[k] = output[i] + 'V';
        k++;
    }
    int smallerOutput2Size = waysToReachBottom(row, col - 1, output);
    for (int i = 0; i < smallerOutput2Size; i++)
    {
        temp[k] = output[i] + 'H';
        k++;
    }

    for (int i = 0; i < smallerOutput1Size + smallerOutput2Size; i++)
    {
        output[i] = temp[i];
    }
    return smallerOutput1Size + smallerOutput2Size;
}

int main()
{

    // cout << numberOfWays(10) << endl;
    string output[1000];
    int a = waysToReachBottom(3, 3, output);
    for (int i = 0; i < a; i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}