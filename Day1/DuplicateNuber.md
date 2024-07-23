# Brute Force : 
---
Do a linear search for each element
`
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 
        // Better Approach : Use a map to store frequency or a set
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
                return nums[i];
            s.insert(nums[i]);
        }
        return -1;
    }
};
`
Optimal Approach : Using Tortoise Method
We treat our array as linked list and apply tortoise method to detect cycle in linked list
Futher we need to find the start of our cycle

int findDuplicate(vector<int>& nums) 
{
    int slow = 0 , fast = 0;
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow != fast);
    
    fast = 0;
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return fast;
        
}