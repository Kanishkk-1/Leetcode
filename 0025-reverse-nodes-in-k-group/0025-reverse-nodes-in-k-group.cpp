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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }

        
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* front = NULL;

        for (int i = 0; i < k; i++) {
            front = temp->next;

            temp->next = prev;
            prev = temp;
            temp = front;
        }
       
            head->next = reverseKGroup(temp, k);

        return prev;
    }
};