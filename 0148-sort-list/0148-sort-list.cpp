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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast != NULL && fast->next != NULL){
             
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* ptr=dummy;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                ptr->next=left;
                ptr=left;
                left=left->next;
            }else{
                ptr->next=right;
                ptr=right;
                right=right->next;
            }
        }
        if(left != NULL)ptr->next=left;
        if(right != NULL)ptr->next=right;
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle=middleNode(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeList(lefthead,righthead);
    }
};