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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* evenhead=head->next;
        ListNode* odd=NULL;
        ListNode* even=NULL;
        ListNode* ptr=head;
        int cnt=1;
        while(ptr != NULL){
             if(cnt%2 == 1){                
                if(odd == NULL){
                    odd=ptr;
                }else{
                    odd->next=ptr;
                    odd=ptr;
                }
             }else{
                if(even == NULL){
                    even=ptr;
                }else{
                    even->next=ptr;
                    even=ptr;
                }
             }
             cnt++;
             ptr=ptr->next;
        }
        even->next=NULL;
        odd->next=evenhead;
        return head;
    }
};