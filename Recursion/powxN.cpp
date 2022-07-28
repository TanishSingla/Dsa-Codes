class Solution
{
public:
    double sol(double &x, int n)
    {
        if (n == 0)
            return 1;
        if ((n % 2 == 0))
            return myPow(x * x, n / 2);
        return x * myPow(x * x, n / 2);
    }
    double sol2(double &x, int n)
    {
        if (n == 0)
            return 1;
        if ((n % 2 == 0))
            return myPow(x * x, n / 2 * (-1));
        return x * myPow(x * x, n / 2 * (-1));
    }
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n > 0)
            return sol(x, n);
        // long long int nn = -1*n;
        return (double)(1.0) / sol2(x, n);
        ;
    }
};

// https://leetcode.com/problems/powx-n/submissions/