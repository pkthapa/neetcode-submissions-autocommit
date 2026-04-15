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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        auto slow = head;
        auto fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto second = slow->next; // Start of second-half of the list
        slow->next = nullptr;

        auto curr = second;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            auto nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        second = prev;
        auto first = head;

        while (second != nullptr) {
            auto tmp1 = first->next;
            auto tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
