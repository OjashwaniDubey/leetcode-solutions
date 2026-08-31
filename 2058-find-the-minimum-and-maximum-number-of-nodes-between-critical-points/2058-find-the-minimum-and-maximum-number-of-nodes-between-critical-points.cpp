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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (firstCritical == -1) {
                    // First critical point
                    firstCritical = index;
                } else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, index - lastCritical);
                }

                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than two critical points
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};