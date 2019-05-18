/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> cache;
        TreeNode* cur = root;
        vector<int> vec;
        while (cur != nullptr || !cache.empty()) {
            if (cur != nullptr) {
                cache.push(cur);
                cur = cur->left;
            } else {
                cur = cache.top();
                vec.push_back(cur->val);
                cache.pop();
                cur = cur->right;
            }
        }
        return vec;
    }
};

