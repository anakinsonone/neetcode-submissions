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
private:
    ListNode *createLinkedList(vector<int> list) {
        ListNode *head = new ListNode(list[0]);
        ListNode *temp = head;
        for(int i = 1; i < list.size(); i++) {
            ListNode *newNode = new ListNode(list[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0, num2 = 0, pow = 1;
        ListNode *temp = l1;
        while(temp) {
            num1 += pow * temp->val;
            temp = temp->next;
            pow *= 10;
        }
        temp = l2;
        pow = 1;
        while(temp) {
            num2 += pow * temp->val;
            temp = temp->next;
            pow *= 10;
        }
        vector<int>res;
        int sum = num1 + num2;
        while(sum>=0) {
            int digit = sum % 10;
            res.push_back(digit);
            sum = sum / 10;
            if(sum == 0) break;
        }
        return createLinkedList(res);
    }
};
