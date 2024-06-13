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

// Listnode* reverse(Listnode* h2){
// Listnode* temp = h2;
// Listnode* prev = NULL;

// while(front!=NULL && front ->next!=NULL){
//     Listnode* front= temp->next;
//     temp->next=prev;
//     prev= temp;
//     temp=front;
// }



// }

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL)return NULL;
        ListNode* temp=head;
      
       
        ListNode* odd = head;

        ListNode* even = head->next;
         ListNode* evenhead = head->next;

        while(even!=NULL && even->next != NULL){
           odd->next=odd->next->next;
           even->next=even->next->next;

           odd= odd->next;
           even=even->next;
        }

        odd->next=evenhead;
        return head;
        
    }
};