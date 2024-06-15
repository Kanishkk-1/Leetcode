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
    ListNode* rotateRight(ListNode* head, int k) {
          if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next != NULL) {

            temp = temp->next;
            len++;
        }

        if (k % len == 0)
            return head;

        k = k % len;

        temp->next = head;
        ListNode* newtail = head;
        int s = (len - k);
        for (int i = 0; i < s-1; i++) {
            newtail = newtail->next;
        }
        head = newtail->next;
        newtail->next = NULL;
        return head;
    }
};