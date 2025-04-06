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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        int sum=0;
        int carry=0;
        while(ptr1 != NULL || ptr2 != NULL){
            sum=carry;
            if(ptr1)sum += ptr1->val;
            if(ptr2)sum += ptr2->val;
            ListNode* newnode=new ListNode(sum%10);
            curr->next=newnode;
            curr=curr->next;
            carry=sum/10;
            if(ptr1)ptr1=ptr1->next;
            if(ptr2)ptr2=ptr2->next;
        }
        if(carry != 0){
            ListNode* newnode=new ListNode(carry);
            curr->next=newnode;
            curr=curr->next;
        }
        return dummy->next;
    }
};