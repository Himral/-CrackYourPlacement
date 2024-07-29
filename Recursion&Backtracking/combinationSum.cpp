class Solution
{
public:
    // return a list of all unique combinations of candidates where the chosen numbers sum to target.
    void generateCombinations(int idx, vector<int> &nums, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (idx == nums.size())
            return;

        // Take
        if (nums[idx] <= target)
        {
            ds.push_back(nums[idx]);
            generateCombinations(idx, nums, target - nums[idx], ds, ans);
            ds.pop_back();
        }

        generateCombinations(idx + 1, nums, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        generateCombinations(0, candidates, target, ds, ans);
        return ans;
    }
};