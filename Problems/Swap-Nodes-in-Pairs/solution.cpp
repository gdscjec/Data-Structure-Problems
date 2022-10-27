class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL)
        {
            swap(curr->val,curr->next->val);
            curr=curr->next->next;
        }
        return head;
    }
};
