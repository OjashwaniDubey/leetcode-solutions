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
    int pairSum(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int ans = 0;
        int i = 0;
        int j = arr.size()-1;
        while(i < j){
            ans = max(ans, arr[i]+arr[j]);
            i++;
            j--;
        }
        return ans;
    }
};