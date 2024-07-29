#include <bits/stdc++.h>
//TC : O(N!)
//SC : O(N)
void backtrack(int idx, string &ds, string &s, vector<string> &ans, set<string> &dictionary)
{
    if (idx == s.length())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        string substring = s.substr(idx, i - idx + 1);
        if (dictionary.find(substring) != dictionary.end())
        {
            ds += (substring + " ");
            backtrack(i + 1, ds, s, ans, dictionary);
            ds.erase(ds.length() - substring.length() - 1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string ds = "";
    set<string> st;
    for (auto it : dictionary)
    {
        st.insert(it);
    }
    backtrack(0, ds, s, ans, st);
    return ans;
}