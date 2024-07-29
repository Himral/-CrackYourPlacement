class Solution
{
public:
    void generateCombinations(int idx, vector<int> &nums, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }

        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            if (nums[i] <= target)
            {
                ds.push_back(nums[i]);
                generateCombinations(i + 1, nums, target - nums[i], ds, ans);
                ds.pop_back();
            }
        }

        // generateCombinations(idx+1,nums,target,ds,ans);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        generateCombinations(0, candidates, target, ds, ans);

        return ans;
    }
};