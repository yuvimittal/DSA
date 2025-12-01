/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
    int sum(Node* root){
        
        if(root == NULL){
            return 0;
        }
        int ans = root->data;
        
        ans = ans + sum(root->left) + sum(root->right);
        
        return ans ;
    }
    
    
    
    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL || (root->left == NULL && root->right == NULL)){ 
            return true;  
        }
        int left = sum(root->left);
        int right = sum(root->right);
        
        if(root->data == (left+right) && isSumTree(root->left) && isSumTree(root->right)){
            return true;
        }
        
        return false;
    }
};