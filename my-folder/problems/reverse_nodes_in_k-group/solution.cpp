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
    // int length(ListNode* head){
    //     int k=0;
    //     while(head!=NULL){
    //       k++;
    //       head=head->next;
    //     }
    //     return k;
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {

         ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }

        if (head==NULL){
            return head;
        }
        int count = 0;
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* next = NULL;
        // int len = length(head);

       while(curr!=NULL && count <k){
           next = curr->next;
           curr->next = prev;
           prev= curr;
           curr=next;
           count++;

         
       }
        // len = len-k;
        

       if(next!=NULL  ){
           head->next = reverseKGroup(curr, k);
       }

    //    else{
    //        return prev->next;
    //    }

       return prev;
        
    }
};