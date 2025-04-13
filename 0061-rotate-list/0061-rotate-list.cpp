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
    void lastnode(ListNode* head,ListNode* &ptr,int &cnt){
        ptr=head;
        while(ptr->next != NULL){
            ptr=ptr->next;
            cnt++;
        }
    }
    ListNode* kthnode(ListNode* head,int k){        
        int cnt=1;
        ListNode* ptr=head;
        while(cnt != k){
            ptr=ptr->next;
            cnt++;
        }
        return ptr;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)return head;
        ListNode* last_ptr=NULL;
        int cnt=1;
        lastnode(head,last_ptr,cnt);
        k=k%cnt;
        if(k == 0)return head;
        ListNode* knode=kthnode(head,cnt-k);
        ListNode* newhead=knode->next;
        knode->next=NULL;
        last_ptr->next=head;
        head=newhead;
        return head;

    }
};