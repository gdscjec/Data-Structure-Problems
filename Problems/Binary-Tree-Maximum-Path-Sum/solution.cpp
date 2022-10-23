class Solution {
public:
   int ans=-1e8;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left= solve(root->left); //traversing left subtree
        int right= solve(root->right);//traversing right subtree
        
        ans= max(ans,max(max(left,right),max(left+right,0))+root->val); //storing max path found
        
        return root->val + max(0,max(right,left));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};