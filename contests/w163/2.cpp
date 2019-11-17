/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> set;
    void recover(TreeNode* root){
        if(root == NULL) return;
        
        if(root->left){
            root->left->val = 2 * root->val + 1;
            set.insert(root->left->val);
        } 
        if(root->right){
            root->right->val = 2 * root->val + 2;
            set.insert(root->right->val);
        } 
        
        recover(root->left);
        recover(root->right);
    }
    
    FindElements(TreeNode* root) {
        
        root->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        if(set.find(target) != set.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */