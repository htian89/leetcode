/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> cache;
        vector<int> vec;
        TreeNode* cur = root;
        while (cur != nullptr || !cache.empty()) {
            if (cur != nullptr) {
                vec.push_back(cur->val);
                cache.push(cur->right);
                cur = cur->left;
            } else {
                cur = cache.top();
                cache.pop();
            }
        }
        return move(vec);
    }
};

