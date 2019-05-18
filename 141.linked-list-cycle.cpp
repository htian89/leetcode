/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        ListNode* quick = head;
        ListNode* slow = head;    
        while (quick != nullptr) {
            if (quick->next == nullptr || quick->next->next == nullptr) return false;
            quick = quick->next->next;
            slow = slow->next;
            if (slow == quick) return true;
        }
        return false;
    }
};

