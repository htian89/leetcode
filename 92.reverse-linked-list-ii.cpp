/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 当m等于n时，不需要操作
        if (m == n) return head;
        ListNode* cur = head;
        // 记录开始和开始的前一个node，结束和结束后一个node
        ListNode* pre_start = nullptr, *after_end = nullptr, *start = nullptr, *end = nullptr;
        ListNode* pre = nullptr;
        for (int i = 1; cur != nullptr && i <= n; ++i) {
            if (i == m - 1) {
                pre_start = cur;
            } else if (i == m) {
                start = cur;
            } else if (i == n) {
                end = cur;
                after_end = cur->next;
            }
            ListNode *tmp = pre;
            pre = cur;
            cur = cur->next;
            if (i >= m) {
                pre->next = tmp;
            }
        }
        // 连接反转部分和未反转部分
        start->next = after_end;
        if (pre_start != nullptr) {
            pre_start->next = end;
            return head;
        }
        return end;
    }
};

