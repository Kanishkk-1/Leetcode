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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* currsum = temp;

        while(currsum!=NULL){
            int sum = 0;
            while(currsum->val!=0){
                sum+=currsum->val;
                currsum = currsum->next;
            }
            temp->val = sum;
            currsum = currsum ->next;
            temp->next = currsum;
            temp= temp->next;
        }
        return head ->next;
    }
};