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
int t=0;
//Function for inorder taversal (left->root->right) keeping track of k
    void inorder(TreeNode* root, int& k)
    {
//We do not visit the the right subtree if k<0 already
        if(!root || k==0) return;
        inorder(root->left,k);
        --k;
        if(k==0) {t = root->val; return;}
        inorder(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return t;
    }
};