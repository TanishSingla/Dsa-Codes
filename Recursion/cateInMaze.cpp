// #include <bits/stdc++.h>
// using namespace std;

// bool isSafe(vector<string> m, int n, vector<vector<int>> visited, int x, int y)
// {
//     if ((x >= 0) && (x < n) && (y >= 0) && (y < n) && (visited[x][y] == 0) && (m[x][y] == 1))
//     {
//         return true;
//     }
//     else
//         return false;
// }
// class Solution
// {
// public:
//     void solve(vector<string> m, int n, int x, int y, string path, vector<string> &ans, vector<vector<int>> visited)
//     {
//         // base condition -> when we reached the destination i.e (n-1)(n-1)
//         if (x == n - 1 &&y = n - 1)
//         {
//             ans.push_back(path);
//             return;
//         }

//         visited[x][y] = 1;

//         // down
//         int newx = x + 1;
//         int newy = y;
//         if (isSafe(m, n, visted, newx, newy))
//         {
//             path.push_back('D');
//             solve(m, n, newx, newy, path, ans, visited);
//             path.pop_back();
//         }
//         // left
//         newx = x;
//         newy = y - 1;
//         if (isSafe(m, n, visted, newx, newy))
//         {
//             path.push_back('L');
//             solve(m, n, newx, newy, path, ans, visited);
//             path.pop_back();
//         }

//         // right
//         newx = x;
//         newy = y + 1;
//         if (isSafe(m, n, visted, newx, newy))
//         {
//             path.push_back('R');
//             solve(m, n, newx, newy, path, ans, visited);
//             path.pop_back();
//         }

//         // up
//         int newx = x - 1;
//         int newy = y;
//         if (isSafe(m, n, visted, newx, newy))
//         {
//             path.push_back('U');
//             solve(m, n, newx, newy, path, ans, visited);
//             path.pop_back();
//         }

//         visited[x][y] = 0;
//     }

// public:
//     vector<string> findPath(vector<vector<int>> &m, int n)
//     {
//         vector<string> ans;
//         if (m[0][0] == 0)
//             return ans;
//         string path = "";
//         int srcx = 0;
//         int srcy = 0;

//         // making a 2d array for checking that place is visited or not..
//         vector<vector<int>> visited = m;
//         for (int i = 0; i < ; i++)
//         {
//             for (int j = 0; j < n; j++)
//                 visited[i][j] = 0;
//         }

//         solve(m, n, srcx, srcy, path, ans, visited);
//     }
// };

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<int>> m(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> m[i][j];
//             }
//         }
//         Solution obj;
//         vector<string> result = obj.findPath(m, n);
//         sort(result.begin(), result.end());
//         if (result.size() == 0)
//             cout << -1;
//         else
//             for (int i = 0; i < result.size(); i++)
//                 cout << result[i] << " ";
//         cout << endl;
//     }
//     return 0;
// }

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, int newx, int newy, vector<vector<int>> visited)
{
    if ((newx >= 0) && newx < n && (newy >= 0 && newy < n) && (m[newx][newy] == 1) && (visited[newx][newy] == 0))
        return true;
    else
        return false;
}
void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited,
           string path)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // up
    newx = x - 1;
    newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        int srcx = 0;
        int srcy = 0;
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
