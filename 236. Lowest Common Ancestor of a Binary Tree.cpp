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
    TreeNode* ans;
    
    bool findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        
        int left = findLCA(root->left, p, q) ? 1 : 0;
        
        int right = findLCA(root->right, p, q) ? 1 : 0;
        
        int mid = (root == p || root == q) ? 1 : 0;
        
        if(mid + left + right >= 2) ans = root;
        
        return (mid | left | right);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLCA(root, p, q);
        
        return ans;
    }
};