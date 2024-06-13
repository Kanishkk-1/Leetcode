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

ListNode* reverse(ListNode* h){
    ListNode* temp = h;
    ListNode* prev = NULL;

    while(temp != NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head->next == NULL && n == 1) return NULL;  
        
        ListNode* reversedHead = reverse(head);

        ListNode* temp = reversedHead;
        if(n == 1){
            ListNode* newHead = reversedHead->next;
            delete reversedHead;  
            return reverse(newHead);
        }

        for(int i = 1; i < n - 1; ++i){
            if(temp != NULL){
                temp = temp->next;
            }
        }

       
        if(temp != NULL && temp->next != NULL){
            ListNode* nodeToRemove = temp->next;
            temp->next = nodeToRemove->next;
            delete nodeToRemove;  
        }

      
        return reverse(reversedHead);
    }
};
