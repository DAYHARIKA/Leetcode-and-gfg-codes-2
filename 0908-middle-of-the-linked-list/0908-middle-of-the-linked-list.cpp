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
    int length(ListNode* head){
        if(head == NULL){
            return 0;
        }
        int cnt=0;
        ListNode* ptr=head;
        while(ptr != NULL){
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int len=length(head);
        int mid=(len/2);
        ListNode* ptr=head;
        int cnt=0;
        while(cnt != mid){
            ptr=ptr->next;
            cnt++;
        }
        return ptr;
    }

};