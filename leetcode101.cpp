//
// Created by endeavor on 2023/8/4.
//
/**
* 对称二叉树
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
*/
#include<iostream>
#include<vector>
#include<queue>
#define null INT16_MIN
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    bool isSame(TreeNode* left, TreeNode* right){
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        else if (left->val != right->val)
            return false;
        else{
            bool inside = isSame(left->right, right->left);
            bool outside = isSame(left->left, right->right);
            bool res = inside && outside;
            return res;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};
TreeNode* createTree(const vector<int>& arr){
    if (arr.empty())
        return nullptr;
    auto* root = new TreeNode(arr.front());
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()){
        TreeNode* cur = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != null){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i] != null){
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}
int main(){
    vector<int> arr = {1,2,2,null,3,null,3};
    TreeNode *root = createTree(arr);
    Solution solution;
    bool result = solution.isSymmetric(root);
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
