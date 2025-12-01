// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//         queue<pair< TreeNode*, pair<int,int>>> q;
//         map<int, map<int, multiset<int>>> m;

//         q.push({root,{0,0}});

//         while(!q.empty()){
            
//             auto front = q.front();
//             q.pop();

//             TreeNode* temp = front.first;

//             int vertical = front.second.first;
//             int level = front.second.second;

//             m[vertical][level].insert(temp->val);

//             if(temp->left){
//                 q.push({temp->left, {vertical-1, level+1} });
//             }

//             if(temp->right){
//                 q.push({temp->right, {vertical+1, level+1} });
//             }
//         }

//         vector<vector<int>> ans;

//         for(auto p: m){
//             vector<int> col;

//             for(auto q: p.second){
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }

//             ans.push_back(col);
//         }

//         return ans;
        

//     }
// };


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>ans;

        map<int,vector<pair<int,int>>>m;
        queue<pair<TreeNode*,int>>q;

        q.push({root,0});
        int level =0;

        while(!q.empty()){
            int s = q.size();
            for(int i =0;i<s;i++){

                int idx = q.front().second;
                TreeNode* temp = q.front().first;
                m[idx].push_back({level,temp->val});
                q.pop();
                

                if(temp->left){
                    q.push({temp->left,idx-1});
                }

                if(temp->right){
                    q.push({temp->right,idx+1});
                }

            }
            level++;
            
        }

        for(auto &x : m){
            vector<pair<int,int>>v =x.second;
            vector<int>a;
            sort(v.begin(),v.end());
            for(int i =0;i<v.size();i++){a.push_back(v[i].second);}
            
            ans.push_back(a);
        }

        return ans;
    }
};