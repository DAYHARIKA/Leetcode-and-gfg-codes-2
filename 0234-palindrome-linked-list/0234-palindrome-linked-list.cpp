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
    bool palindrome(vector<int> arr){
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l <= h){
            if(arr[l] != arr[h])return false;
            l++;
            h--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
         vector<int> temp;
         ListNode* ptr=head;
         while(ptr != NULL){
            temp.push_back(ptr->val);
            ptr=ptr->next;
         }
         return palindrome(temp);
    }
};