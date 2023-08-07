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
    ListNode* deleteDuplicates(ListNode* head) {

       ListNode* temp = head;

       while(temp!=NULL){

           if(temp->next!=NULL&& temp->val == temp->next->val){
              
                temp->next = temp->next->next;
           }

            else{
               temp= temp->next;
            }
      }
      return head;


      // map <ListNode* , bool> vis;
      // ListNode* temp = head;
      // ListNode* prev = head;

      // while(temp!=NULL){

      //   if(vis[temp->val]==true){

            
      //     }
      
      //      vis[temp->val]=true;
       
      //     temp = temp->next;
      //     prev = prev->next; 

      // }
       }   
    
};