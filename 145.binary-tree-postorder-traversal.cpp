/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> cache;
        if (root != nullptr) cache.push(root);       
        vector<int> vec;
        TreeNode* pre = nullptr;
        while(!cache.empty()) {
            TreeNode* cur = cache.top();
            if ((cur->left == nullptr && cur->right == nullptr) ||
                (pre != nullptr && (cur->left == pre || cur->right == pre))) {
                cache.pop();
                vec.push_back(cur->val);
                pre = cur;
            } else {
                if (cur->right != nullptr) cache.push(cur->right);
                if (cur->left != nullptr) cache.push(cur->left);
            }
        }
        return move(vec);
    }
};

