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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* left = head;
        ListNode* right = head;
        
        while (n-- > 0) {
            right = right->next;
        }

        ListNode* prev = dummy;
        while (right != nullptr) {
            prev = prev->next;
            left = left->next;
            right = right->next;
        }

        prev->next = left->next;
        delete left;
        return dummy->next;
    }
};
