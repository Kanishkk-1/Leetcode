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

ListNode* ReverseLinkedList(ListNode* head2){
    ListNode* prev= NULL;
    ListNode* temp= head2;

    while(temp!=NULL){
        ListNode* front = temp->next;
        temp->next= prev;
        prev= temp;
        temp=front;

    }
return prev;
} 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast= head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
       ListNode* first = head;
       ListNode* second = ReverseLinkedList(slow);
     
        while(second!=NULL){
          if(first->val!=second->val){
        //    ReverseLinkedList(slow);
           return false;
          }
         first=first->next;
         second=second->next;
        }

return true;
    }
};
