// TC : O(N)
// SC: O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int uniqueIndex = 0, duplicateIndex = 0;

        while (duplicateIndex < nums.size())
        {
            if (nums[duplicateIndex] != nums[uniqueIndex])
            {
                nums[++uniqueIndex] = nums[duplicateIndex];
            }
            duplicateIndex++;
        }
        return uniqueIndex;
    }
};