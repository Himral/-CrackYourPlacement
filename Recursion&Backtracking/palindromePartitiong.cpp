class Solution
{
public:
    // Partition at index idx
    bool isPalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return (s == rev);
    }
    void validPartitions(int idx, string s, vector<string> &ds, vector<vector<string>> &ans)
    {
        if (idx == s.length())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < s.length(); i++)
        {
            string substring = s.substr(idx, i - idx + 1);
            // cout << "idx : " << idx << " i : " << i << "substring : " << substring << "\n";
            if (isPalindrome(substring))
            {
                ds.push_back(substring);
                validPartitions(i + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        validPartitions(0, s, ds, ans);
        return ans;
    }
};