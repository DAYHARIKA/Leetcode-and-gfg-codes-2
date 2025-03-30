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
    ListNode* middleNode(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr != NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         
         //middlenode
         if(head == NULL || head->next == NULL)return true;
         ListNode* middle=middleNode(head);
         ListNode* reverse=reverseList(middle);
         
         ListNode* head1=head;
         ListNode* head2=reverse;
         bool is_pali=true;
         while(head2 != NULL){
            if(head1->val != head2->val){
               is_pali=false;
               break;
            }
            head1=head1->next;
            head2=head2->next;
         }
         reverseList(reverse);
         return is_pali;
    }
};