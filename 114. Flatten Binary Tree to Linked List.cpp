/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void preOrder(TreeNode* node){
        if(node == nullptr) return;
        
        
        preOrder(node->left);
        preOrder(node->right);
        
        TreeNode* tmp = node->right;
        node->right = node->left;
        node->left = nullptr;
        while (node->right)
            node = node->right;
        node->right = tmp;
    }
    
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        preOrder(root);
    }
};