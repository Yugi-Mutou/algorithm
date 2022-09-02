class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>q;
        vector<int> ans;
        TreeNode* now=root;
        while(now||!q.empty()){
            while(now){
                ans.push_back(now->val);
                q.emplace(now);
                now=now->left;
            }
            //每次从栈中出现的值，我都取它的右结点
            TreeNode* temp=q.top();
            q.pop();
            now=temp->right;

        }
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* now=root;
        while(now||!st.empty()){
            while(now){
                st.emplace(now);
                now=now->left;
            }
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            // 已经遍历过的结点不会再遍历一次
            // 切到右结点
            temp=temp->right;
            now=temp;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* now=root;
        // prev等于出栈的元素
        TreeNode* prev=nullptr;
        while(now||!st.empty()){
            while(now){
                st.emplace(now);
                now=now->left;
            }
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right==nullptr||temp->right==prev){
                prev=temp;
                ans.push_back(temp->val);
                now=nullptr;
            }else{
                st.push(temp);
                now=temp->right;
            }
        }
        return ans;
    }
};