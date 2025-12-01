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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* returnTree= root;
        TreeNode* temp=  new TreeNode(val);

        if(!root){
            return temp;
        }

        while(root){
        if(val > root->val){
            if(!root->right){
                root->right = temp;
                break;
            }else {
            root= root->right;
            }
        }else {
            if(!root->left){
                root->left = temp;
                break;
            }else {
            root= root->left;
            }     
        }
        }
return returnTree;

    }
};