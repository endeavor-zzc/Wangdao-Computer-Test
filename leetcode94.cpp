//
// Created by endeavor on 2023/8/3.
//
/**
* 二叉树的中序遍历
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
*/
#include<iostream>
#include<vector>
#include<queue>
#define null INT16_MIN
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    void inorder(TreeNode *root, vector<int> &res){
        if (root){
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode *root){
    vector<int> result;
        inorder(root, result);
        return result;
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
void PrintTree(const vector<int>& arr){
    cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1){
            cout << ",";
        }
    }
    cout << "]" << endl;
}
int main(){
    vector<int> arr = {1, null, 2, 3};
    TreeNode *root = createTree(arr);
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    PrintTree(result);
    return 0;
}
