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
         int l=0;
         while(head!=NULL){
             head=head->next;
             l++;
         }
         return l;
     }
    int getDecimalValue(ListNode* head) {
       int len = length(head);
        ListNode* temp=head;
       int k=(len-1);

        int ans=0;

        while(temp!=NULL){
            ans+=(temp->val)*pow(2,k);
            temp=temp->next;
            k--;
        }
    return ans;
    }
};