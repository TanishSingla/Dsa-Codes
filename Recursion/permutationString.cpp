#include <bits/stdc++.h>
using namespace std;
void solve(string s, int index, vector<string> &ans)
{
    // base condition
    if (index >= s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int j = index; j < s.length(); j++)
    {
        swap(s[index], s[j]);
        solve(s, index + 1, ans);
        swap(s[index], s[j]);
    }
}

void solve2(vector<int> input, int index, vector<vector<int>> &ans)
{
    if (index >= input.size())
    {
        ans.push_back(input);
        return;
    }

    for (int i = index; i < input.size(); i++)
    {
        swap(input[i], input[index]);
        solve2(input, index + 1, ans);
        swap(input[i], input[index]);
    }
}

int main()
{

    // input -> abc
    // output -> abc acb bca bac cba cab ( n! )
    /*
    string s;
    cin >> s;
    vector<string> ans;
    int index = 0;
    solve(s, index, ans);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    */

       return 0;
}