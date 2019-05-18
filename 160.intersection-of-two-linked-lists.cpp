/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA, *pB = headB;
        // 如果没有交点会同时到达nullptr，否则在焦点相遇
        while (pA != pB) {
            pA = (pA != nullptr) ? pA->next : headB;
            pB = (pB != nullptr) ? pB->next : headA;
        }
        return pA;
    }
};

