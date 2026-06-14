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
        //vector<int>arr;
        //while(head){
        //    arr.push_back(head->val);
        //    head = head->next;
        //}
        //int ans = 0;
        //int i = 0;
        //int j = arr.size()-1;
        //while(i < j){
        //    ans = max(ans, arr[i]+arr[j]);
        //    i++;
        //    j--;
        //}
        //return ans;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode* p1 = head;
        ListNode* p2 = prev;
        int ans = 0;
        while(p2){
            ans = max(ans, p1->val+p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        return ans;
    }
};