/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        ListNode* slow = start;
        ListNode* fast = start;
        slow->next = head;
        
        //Move fast in front so that the gap between slow and fast becomes n
        for(int i=1; i<=n+1; i++)   {
            fast = fast->next;
        }
        //Move fast to the end, maintaining the gap
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        //Skip the desired node
        slow->next = slow->next->next;
        return start->next;
    }
};