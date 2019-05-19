/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode dummy_header(0);
      ListNode* cur = &dummy_header;
      while (l1 != nullptr || l2 != nullptr) {
        cur->next = new ListNode(carry);
        cur = cur->next;
        if (l1 != nullptr) {
            cur->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            cur->val += l2->val;
            l2 = l2->next;
        }
        carry = cur->val / 10;
        cur->val %= 10;
      }
      if (carry != 0) {
        cur->next = new ListNode(carry);
      }
      return dummy_header.next;
    }
};

