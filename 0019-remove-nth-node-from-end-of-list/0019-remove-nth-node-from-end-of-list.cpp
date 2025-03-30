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
        int cnt=0;
        ListNode* ptr=head;
        while(ptr != NULL){
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)return head;
        int len=length(head);
        int k=len-n+1;
        if(k == 1){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        ListNode* ptr=head;
        int cnt=1;
        while(cnt < k-1){
            ptr=ptr->next;
            cnt++;
        }
        ListNode* temp1=ptr->next;
        ptr->next=temp1->next;
        delete(temp1);
        return head;
    }
};