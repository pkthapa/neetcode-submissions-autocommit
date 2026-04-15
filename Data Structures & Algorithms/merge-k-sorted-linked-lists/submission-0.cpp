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
    struct mycomparator {
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycomparator> minHeap;
        
        // Insert only the first nodes from all the given lists.
        for (auto& list : lists) {
            minHeap.push(list);
        }

        ListNode* mergedList = nullptr;
        ListNode* dummy = new ListNode;
        while (!minHeap.empty()) {
            auto node = minHeap.top();
            minHeap.pop();

            if (mergedList == nullptr) {
                mergedList = node;
                dummy->next = mergedList;
            }
            else {
                mergedList->next = node;
                mergedList = mergedList->next;
            }

            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }
        return dummy->next;
    }
};
