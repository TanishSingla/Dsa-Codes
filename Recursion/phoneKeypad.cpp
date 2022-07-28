#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= input.length())
    {
        ans.push_back(output);
        return;
    }

    int num = input[index] - '0';
    string val = mapping[num];
    for (int i = 0; i < val.length(); i++)
    {
        output.push_back(val[i]);
        solve(input, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string input)
{
    vector<string> ans;
    if (input.length() == 0)
        return ans;
    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(input, output, index, ans, mapping);
    return ans;
}

int main()
{

    string input = "234";
    vector<string> s = letterCombination(input);
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;

    return 0;
}