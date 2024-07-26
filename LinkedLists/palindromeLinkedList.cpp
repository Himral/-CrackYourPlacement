// Method1 : Using stack
//TC: O(N) + O(N)
//SC: O(N)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;

        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            if (st.top() != temp->val)
                return false;
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};
// Method 2: Reverse the first half and then comparing
// TC :
// SC : O(N)
bool isPalindrome(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    stack<int> s;
    s.push(slow->val);
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        s.push(slow->val);
    }

    s.pop();
    if (fast)
    {
        slow = slow->next;
    }
    while (!s.empty())
    {
        if (s.top() != slow->val)
        {
            return false;
        }

        s.pop();
        slow = slow->next;
    }
    return true;
}