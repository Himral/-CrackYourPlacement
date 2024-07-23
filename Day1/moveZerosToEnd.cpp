//TC : O(N)
//SC : O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeroIdx = 0, idx = 0;

        while (idx < nums.size())
        {
            if (nums[idx] != 0)
            {
                nums[nonZeroIdx++] = nums[idx];
            }
            idx++;
        }

        while (nonZeroIdx < nums.size())
        {
            nums[nonZeroIdx++] = 0;
        }
    }
};