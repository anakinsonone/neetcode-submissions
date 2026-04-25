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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>values;
        for(ListNode* l: lists) {
            while(l) {
                values.push_back(l->val);
                l = l->next;
            }
        }
        sort(values.begin(), values.end());

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        for(int n: values) {
            curr->next = new ListNode(n);
            curr = curr->next;
        }
        return head->next;
    }
};
