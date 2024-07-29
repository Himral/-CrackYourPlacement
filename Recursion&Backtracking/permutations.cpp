class Solution
{
public:
    void generatePermutations(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            generatePermutations(idx + 1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        generatePermutations(0, nums, ans);
        return ans;
    }
};