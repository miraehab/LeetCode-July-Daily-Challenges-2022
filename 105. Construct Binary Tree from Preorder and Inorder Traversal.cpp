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
    TreeNode* retriveOriginal(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = retriveOriginal(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = retriveOriginal(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return retriveOriginal(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};