// Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/
#include <bits/stdc++.h>
using namespace std;
int numUniqueEmails(vector<string> &emails)
{
    int n = emails.size();
    unordered_set<string> ans;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        string s = emails[i];
        while (true)
        {
            if (s[j] == '@')
                break;
            if (s[j] == '+')
            {
                s.erase(j, s.find('@') - j);
                break;
            }
            if (s[j] == '.')
            {
                s.erase(j, 1);
            }
            else
                j++;
        }
        ans.insert(s);
    }
    return ans.size();
}
int main()
{

    return 0;
}
